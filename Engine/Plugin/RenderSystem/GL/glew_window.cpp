//
// Created by huxf on 2016/7/27.
//
#include <iostream>
#include <GL/glew.h>
#include "glew_window.h"
#include "../../../Framework/log_manager.h"

using namespace std;

GLEWWindow::GLEWWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    #if MAGIC_PLATFORM == MAGIC_PLATFORM_APPLE
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
}

GLEWWindow::~GLEWWindow()
{

}

void GLEWWindow::Destroy() {

}

void GLEWWindow::Create(const string &title, unsigned int width, unsigned int height)
{
    window_ = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if(!window_)
    {
        Magic::LogManager::GetInstance().LogMessage(" Create Window Failed");
        glfwTerminate();
        return;
    }

    glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

//    glfwSetKeyCallback(window_,keyCallBack);
//    glfwSetScrollCallback(window_,scrollBack);
//    glfwSetMouseButtonCallback(window_,mouseButtonCallback);
//    glfwSetCursorPosCallback(window_,cursorPosCallback);

    glfwMakeContextCurrent(window_);

    int w,h;
    glfwGetFramebufferSize(window_,&w,&h);
    glViewport(0,0,w,h);

    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit())
    {
        Magic::LogManager::GetInstance().LogMessage("glew init Failed");
        return;
    }

    while (!glfwWindowShouldClose(window_))
    {
        cout << "Create" << endl;
        glfwPollEvents();

        glClearColor(.0f, .0f, .0f, .0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window_);
    }
    cout << "Create" << endl;

    //TODO 销毁资源
    glfwTerminate();
}

void GLEWWindow::AddViewport(Camera *camera)
{
    RenderWindow::AddViewport(camera);
}

void keyCallBack(GLFWwindow* window,int key,int scancode,int action,int mods);
void scrollBack(GLFWwindow* window,double xoffset,double yoffset);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);

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

