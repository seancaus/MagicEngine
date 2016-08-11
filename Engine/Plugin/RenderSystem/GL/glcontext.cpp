//
// Created by huxf on 2016/8/11.
//

#include "glcontext.h"

GLContext::GLContext(GLFWwindow* window_):
window_(window_)
{

}
//-----------------------------------------------------------------------
GLContext::~GLContext()
{

}
//-----------------------------------------------------------------------
void GLContext::setCurrent()
{
    glfwMakeContextCurrent(window_);
}
//-----------------------------------------------------------------------