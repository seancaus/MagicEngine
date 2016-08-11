//
// Created by huxf on 2016/8/11.
//

#ifndef MAGIC_GLCONTEXT_H
#define MAGIC_GLCONTEXT_H

#include <GLFW/glfw3.h>

class GLContext
{

public:
    GLContext(GLFWwindow* window_);
    virtual ~GLContext();

    virtual void setCurrent();

private:

    GLFWwindow* window_;
};


#endif //MAGIC_GLCONTEXT_H
