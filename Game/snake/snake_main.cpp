//
// Created by huxf on 2016/8/22.
//
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>
#include <sstream>
#include "../../Engine/Framework/gpu_program.h"
#include "map.h"
#include "snake.h"


using namespace std;
using namespace Magic;

int main ()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);

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


    float vertexs[] = {-0.05f,  0.05f,.0,1
                        ,0.05f, -0.05f,0,1
                        ,0.05f, -0.05f,0,1
    };
//
    glm::vec2 translations[100];
    int index = 0;
    GLfloat offset = 0.1f;
    for(GLint y = -10; y < 10; y += 2)
    {
        for(GLint x = -10; x < 10; x += 2)
        {
            glm::vec2 translation;
            translation.x = (GLfloat)x / 10.0f + offset;
            translation.y = (GLfloat)y / 10.0f + offset;
            translations[index++] = translation;
        }
    }
//
    GLuint vao,vbo,instanceVBO;
    glGenVertexArrays(1,&vao);
    glGenBuffers(1,&vbo);
    glGenBuffers(1,&instanceVBO);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexs),vertexs,GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,4* sizeof(float),(GLvoid*)0);

//    glBindBuffer(GL_ARRAY_BUFFER,instanceVBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*100,&translations[0],GL_STATIC_DRAW);
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,2* sizeof(glm::vec2),(GLvoid*)0);

    glBindBuffer(GL_VERTEX_ARRAY,0);
//    glVertexAttribDivisor(1,1);
    glBindVertexArray(0);

    GPUProgram program("../Assets/glsl/point.vert","../Assets/glsl/point.frag");

    glPointSize(30);
    Snake snake;
    snake.preBind();
    while(!glfwWindowShouldClose(window))
    {
//        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
//        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

        glfwPollEvents();

        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);

//        for(GLuint i = 0; i < 100; i++)
//        {
//            stringstream ss;
//            string index;
//            ss << i;
//            index = ss.str();
//            program.setUniform2f(("offsets[" + index + "]").c_str(),translations[i].x, translations[i].y);
//        }

//        program.use();
//        glBindVertexArray(vao);

//        glDrawArrays(GL_POINTS,0,1);
//        glDrawArraysInstanced(GL_POINTS,0,1,100);
//        glBindVertexArray(0);
        snake.move();
        snake.draw();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}