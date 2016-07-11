//
// Created by Ziv on 16/7/10.
//
#include <iostream>
#include <GL/glew.h>
#include <glog/logging.h>

#include "application.h"

#include "panel.h"

using namespace std;

static const int WIDTH = 640;
static const int HEIGHT = 480;

Application::Application():
_window(nullptr)
{
    //INFO, WARNING, ERROR, and FATAL
    google::InitGoogleLogging("INFO");
}


Application::~Application()
{
    _window = nullptr;
}


Application* Application::application = nullptr;
Application& Application::getInstance()
{
    if( !Application::application )
    {
        //TODO (std::nothrow)
        application = new (std::nothrow) Application();
    }
    return *application;
}


int Application::run()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    _window = glfwCreateWindow(WIDTH,HEIGHT,"TEST",nullptr,nullptr);

    if(!_window)
    {
        LOG(FATAL) << "\"glfw\" Create Window Failed" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(_window);

    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit())
    {
        LOG(FATAL) << "glew init Failed" << endl;
        glfwTerminate();
        return -1;
    }

    int width,height;
    glfwGetFramebufferSize(_window,&width,&height);
    glViewport(0,0,width,height);

    Panel p;
    p._color = {.2,.3,.4,.5};
    p._size = {100,100};
    p._position = {300,200,0};

    p.preBind();
    while (!glfwWindowShouldClose(_window)) {
        glfwPollEvents();

        glClearColor(.0f, .0f, .0f, .0f);
        glClear(GL_COLOR_BUFFER_BIT);

        p.draw();

        glfwSwapBuffers(_window);
    }

    //TODO 销毁资源
    glfwTerminate();
    return 0;
}

void Application::close()
{
    glfwSetWindowShouldClose(_window, GL_TRUE);
}