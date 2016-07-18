//
// Created by Ziv on 16/7/10.
//
#include <iostream>
#include <GL/glew.h>
#include "game_mode.h"

//#include <glog/logging.h>

#include "panel.h"

static float WIDTH = 640;
static float HEIGHT = 480;

using namespace std;


GameMode::GameMode():
        window_(nullptr)
{
    //INFO, WARNING, ERROR, and FATAL
//    google::InitGoogleLogging("INFO");
}


GameMode::~GameMode()
{
    window_ = nullptr;
}


GameMode* GameMode::instance = nullptr;
GameMode& GameMode::getInstance()
{
    if( !GameMode::instance )
    {
        //TODO (std::nothrow)
        instance = new (std::nothrow) GameMode();
    }
    return *instance;
}


int GameMode::Run()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window_ = glfwCreateWindow(WIDTH,HEIGHT,"TEST",nullptr,nullptr);

    if(!window_)
    {
//        LOG(FATAL) << "\"glfw\" Create Window Failed" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window_);

    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit())
    {
//        LOG(FATAL) << "glew init Failed" << endl;
        glfwTerminate();
        return -1;
    }

    int width,height;
    glfwGetFramebufferSize(window_,&width,&height);
    glViewport(0,0,width,height);

    Panel p;
    p._color = {.2,.3,.4,.5};
    p._size = {100,100};
    p._position = {300,200,0};

    p.preBind();
    while (!glfwWindowShouldClose(window_)) {
        glfwPollEvents();

        glClearColor(.0f, .0f, .0f, .0f);
        glClear(GL_COLOR_BUFFER_BIT);

        p.draw();

        glfwSwapBuffers(window_);
    }

    //TODO 销毁资源
    glfwTerminate();
    return 0;
}

void GameMode::Close()
{
    glfwSetWindowShouldClose(window_, GL_TRUE);
}