//
// Created by Ziv on 16/8/26.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "cube.h"
#include "cube_game_model.h"

void onKeyCallback(GLFWwindow* window,int key,int scanCode,int action,int mode);
void onMouseCallback(GLFWwindow* window,double xpos,double ypos);

static CubeGameModel* pgm = nullptr;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(500,500,"CUBE", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if(GLEW_OK != glewInit())
    {
        cout << "ERROR glewInit" << endl;
        return -1;
    }

    glfwSetKeyCallback(window,onKeyCallback);
    glfwSetCursorPosCallback(window,onMouseCallback);

    int w,h;
    glfwGetFramebufferSize(window,&w,&h);
    glViewport(0,0,w,h);


    CubeGameModel gm;
    pgm = &gm;
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(.0,.0,.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        gm.renderOneFrame();

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}

void onKeyCallback(GLFWwindow* window,int key,int scanCode,int action,int mode)
{
    pgm->onKeyCallback(window,key,scanCode,action,mode);
}

void onMouseCallback(GLFWwindow* window,double xpos,double ypos)
{
    pgm->onMouseMoveCallback(window,xpos,ypos);
}