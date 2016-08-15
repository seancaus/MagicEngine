//
// Created by huxf on 2016/8/15.
//

#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

using namespace std;

int main(int argc, char **argv)
{

    if ( !glfwInit() )
    {
        cout << "glfwInit failed" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(300,300,"test", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if(GLEW_OK != glewInit())
    {
        cout << "glewInit failed" << endl;
        glfwTerminate();
        return -1;
    }

    int w,h;
    glfwGetFramebufferSize(window,&w,&h);
    glViewport(0,0,w,h);

    GLuint buffer;
    glGenBuffers(1,&buffer);
    glCreateBuffers(1,&buffer);

    while( !glfwWindowShouldClose(window) )
    {
        glfwPollEvents();

        glClearColor(.0,.0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    cout << "test" << endl;
    return 0;
}