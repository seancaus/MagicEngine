//
// Created by huxf on 2016/8/22.
//
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../Engine/Framework/gpu_program.h"

using namespace std;
using namespace Magic;

int main ()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(500,500,"snake",nullptr,nullptr);
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

    GPUProgram program("../Assets/glsl/point.vert","../Assets/glsl/point.frag");

    float vertexs[] = {.0,.0,.0,1
                        ,1,0,0,1
                        ,.5,.5,0,1
    };

    GLuint vao,vbo;
    glGenVertexArrays(1,&vao);
    glGenBuffers(1,&vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexs),vertexs,GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,4* sizeof(float),(GLvoid*)0);

    glBindBuffer(GL_VERTEX_ARRAY,0);
    glBindVertexArray(0);

    while(!glfwWindowShouldClose(window))
    {
//        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
//        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

        glfwPollEvents();

        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(vao);
        program.use();
//        glPointSize(50);
//        glDrawArrays(GL_POINTS,0,1);
        glDrawArrays(GL_TRIANGLES,0,3);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}