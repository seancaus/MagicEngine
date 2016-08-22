//
// Created by Ziv on 16/8/21.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int main3()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);

    GLFWwindow * window = glfwCreateWindow(500,500,"test FBO",nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    glewInit();

    GLuint fbo,rbo;
    glGenFramebuffers(1,&fbo);
    glBindFramebuffer(GL_FRAMEBUFFER,fbo);

    glGenRenderbuffers(1,&rbo);
    glBindRenderbuffer(GL_RENDERBUFFER,rbo);
    glRenderbufferStorage(GL_RENDERBUFFER,GL_RGBA,100,100);


    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    return 0;
}