//
// Created by huxf on 2016/7/19.
//
#include <iostream>
#include <GL/glew.h>
#include "application.h"
#include "cube_game_mode.h"

using namespace std;

static float WIDTH = 640;
static float HEIGHT = 480;

Application* Application::instance = nullptr;
Application& Application::GetInstance()
{
    if(!instance)
    {
        instance = new (std::nothrow) Application();
    }
    return *instance;
}

Application::Application():
game_mode_(nullptr)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

}

Application::~Application()
{
    window_ = nullptr;
}

void keyCallBack(GLFWwindow* window,int key,int scancode,int action,int mods);
void scrollBack(GLFWwindow* window,double xoffset,double yoffset);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);

int Application::Run()
{
    window_ = glfwCreateWindow(WIDTH,HEIGHT,"TEST",nullptr,nullptr);

    if(!window_)
    {
//        LOG(FATAL) << "\"glfw\" Create Window Failed" << endl;
        glfwTerminate();
        return -1;
    }

    glfwSetInputMode(window_,GLFW_CURSOR,GLFW_CURSOR_HIDDEN);

    glfwSetKeyCallback(window_,keyCallBack);
    glfwSetScrollCallback(window_,scrollBack);
    glfwSetMouseButtonCallback(window_,mouseButtonCallback);
    glfwSetCursorPosCallback(window_,cursorPosCallback);

    glfwMakeContextCurrent(window_);

    int width,height;
    glfwGetFramebufferSize(window_,&width,&height);
    glViewport(0,0,width,height);

    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit())
    {
//        LOG(FATAL) << "glew init Failed" << endl;
        cout << "glew init Failed" << endl;
        return -1;
    }

    game_mode_ = new CubeGameMode();
    while (!glfwWindowShouldClose(window_)) {
        glfwPollEvents();

        glClearColor(.0f, .0f, .0f, .0f);
        glClear(GL_COLOR_BUFFER_BIT);

//        if (game_mode_) {
        game_mode_->MainLoop();
//        }else{
//            cout <<"gameMode is nullptr" << endl;
//        }
        glfwSwapBuffers(window_);
    }

    //TODO 销毁资源
    glfwTerminate();
    return 0;
}

void Application::Close()
{
    glfwSetWindowShouldClose(window_, GL_TRUE);
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