//
// Created by huxf on 2016/7/21.
//
#include <iostream>
#include <GL/glew.h>
#include "render_window.h"

using namespace std;


RenderWindow::RenderWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

}


RenderWindow::~RenderWindow() {

}

void keyCallBack(GLFWwindow* window,int key,int scancode,int action,int mods);
void scrollBack(GLFWwindow* window,double xoffset,double yoffset);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);

void RenderWindow::CreateWindow(unsigned int width, unsigned int height,std::string& title)
{
    window_ = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if(!window_)
    {
//        LOG(FATAL) << "\"glfw\" Create Window Failed" << endl;
        glfwTerminate();
        return;
    }

    glfwSetInputMode(window_,GLFW_CURSOR,GLFW_CURSOR_HIDDEN);

    glfwSetKeyCallback(window_,keyCallBack);
    glfwSetScrollCallback(window_,scrollBack);
    glfwSetMouseButtonCallback(window_,mouseButtonCallback);
    glfwSetCursorPosCallback(window_,cursorPosCallback);

    glfwMakeContextCurrent(window_);

    int w,h;
    glfwGetFramebufferSize(window_,&w,&h);
    glViewport(0,0,w,h);

    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit())
    {
//        LOG(FATAL) << "glew init Failed" << endl;
        cout << "glew init Failed" << endl;
        return;
    }

    while (!glfwWindowShouldClose(window_)) {
        glfwPollEvents();

        glClearColor(.0f, .0f, .0f, .0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window_);
    }

    //TODO 销毁资源
    glfwTerminate();
}


void RenderWindow::AddViewport(Camera *camera) {

}


void keyCallBack(GLFWwindow* window,int key,int scancode,int action,int mods)
{
    if (GLFW_RELEASE != action) return;

    if( GLFW_KEY_ESCAPE == key)
    {
        glfwSetWindowShouldClose(window,GL_TRUE);
    }
    cout << "key:" << key<< "scancode:" << scancode << " mods:"<<mods << endl;
}

void scrollBack(GLFWwindow* window,double xoffset,double yoffset)
{
    cout << "xoffset:" << xoffset<< "yoffset:" << yoffset << endl;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
//    action One of `GLFW_PRESS` or `GLFW_RELEASE`.
}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    cout << "xpos:" << xpos<< "ypos:" << ypos << endl;
}