//
// Created by huxf on 2016/8/19.
//
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "../Engine/Framework/gpu_program.h"

using namespace std;
using namespace magic;

const static int IMAGE_WIDTH = 1024;
const static int IMAGE_HEIGHT = 1024;
const static int IMAGE_CHANNEL = 4;
const int DATA_SIZE = IMAGE_WIDTH*IMAGE_HEIGHT*IMAGE_CHANNEL;

void fullPBO(GLuint tex,GLint pbo)
{

}

void updatePixel(GLubyte* dptr,int width,int height)
{
    int* ptr = (int*)dptr;
    static int color = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            *ptr = color;
            ++ptr;
        }
        color += 257;
    }
    ++color;
}

int main4() {

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    GLFWwindow *window = glfwCreateWindow(400, 400, "TEST PBO", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if(GLEW_OK != glewInit())
    {
        cout << "ERROR glewInit" << endl;
        return -1;
    }

    int w,h;
    glfwGetFramebufferSize(window,&w,&h);
    glViewport(0,0,w,h);


    GLint indexs[] = {0,1,2  ,0,3,1};
    GLfloat data[] = {
            -.5,-.5,0,1     ,.5,.5,0,1      ,-.5,.5,0,1     ,.5,-.5,0,1
            ,0,0            ,1,1            ,0,1            ,1,0
    };

    GLuint vao,vbo,ebo,pbos[2],tex;
    glGenVertexArrays(1,&vao);
    glGenBuffers(1,&vbo);
    glGenBuffers(1,&ebo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(data) ,data, GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,4* sizeof(float),(GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,2* sizeof(float),(GLvoid*)(16* sizeof(float)));
    glEnableVertexAttribArray(1);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexs),indexs, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

    glGenTextures(1,&tex);
    glBindTexture(GL_TEXTURE_2D,tex);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,1024,1024,0,GL_RGBA,GL_UNSIGNED_BYTE, nullptr);
    glBindTexture(GL_TEXTURE_2D,0);

    glGenBuffers(2,pbos);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER,pbos[0]);
    glBufferData(GL_PIXEL_UNPACK_BUFFER,DATA_SIZE, nullptr,GL_STREAM_DRAW);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER,pbos[1]);
    glBufferData(GL_PIXEL_UNPACK_BUFFER,DATA_SIZE, nullptr,GL_STREAM_DRAW);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER,0);


    GPUProgram program("../Assets/glsl/vertex.glsl","../Assets/glsl/fragment.glsl");



    int index = 0;
    int nextIndex = 0;
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        program.use();
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,tex);

        index = (index+1)%2;
        nextIndex = (index+1)%2;

//        cout << "index:"<<index<<" nextIndex:"<<nextIndex << endl;

        glBindBuffer(GL_PIXEL_UNPACK_BUFFER,pbos[index]);
        glTexSubImage2D(GL_TEXTURE_2D,0,0,0,IMAGE_WIDTH,IMAGE_HEIGHT,GL_RGBA,GL_UNSIGNED_BYTE,0);
        glBindBuffer(GL_PIXEL_UNPACK_BUFFER,0);

        glBindBuffer(GL_PIXEL_UNPACK_BUFFER,pbos[nextIndex]);
        glBufferData(GL_PIXEL_UNPACK_BUFFER,DATA_SIZE,0,GL_STREAM_DRAW);
        GLubyte* ptr = (GLubyte*)glMapBuffer(GL_PIXEL_UNPACK_BUFFER,GL_READ_WRITE);
        updatePixel(ptr,IMAGE_WIDTH,IMAGE_HEIGHT);
        glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);
        glBindBuffer(GL_PIXEL_UNPACK_BUFFER,0);

        program.setUniform1i("samp",0);

        glBindVertexArray(vao);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);

        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT, nullptr);

        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}