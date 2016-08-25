//
// Created by huxf on 2016/8/22.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "snake.h"
#include "map.h"
#include <unistd.h>

using namespace std;
using namespace magic;

static Snake* pSnake = nullptr;
void keyCallback(GLFWwindow*,int,int,int,int);

GLfloat deltaTime = .0;
GLfloat lastFrame = .0;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
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

    glfwSetKeyCallback(window,keyCallback);

    int w,h;
    glfwGetFramebufferSize(window,&w,&h);
    glViewport(0,0,w,h);

    Snake snake;
    Map map;
    snake.preBind();
    map.preBind();
    pSnake = &snake;
    while(!glfwWindowShouldClose(window))
    {
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

//        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
//        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

        glfwPollEvents();

        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);

        map.draw();
        snake.move();
        snake.draw();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

void keyCallback(GLFWwindow* window,int key,int scancode,int action,int mods)
{
//    cout << key << ",scancode:" << scancode<< ",action:"<< action << endl;

    if(action != GLFW_PRESS) return;

    if(key == GLFW_KEY_UP)
    {
        pSnake->setForward(true);
    }else if(key == GLFW_KEY_DOWN)
    {
        pSnake->setForward(false);
    }else if(key == GLFW_KEY_LEFT)
    {
        pSnake->setRight(false);
    }
    else if(key == GLFW_KEY_RIGHT)
    {
        pSnake->setRight(true);
    }

    if (pSnake->getLength() <= 4)
    {
        pSnake->grow();
    }

}