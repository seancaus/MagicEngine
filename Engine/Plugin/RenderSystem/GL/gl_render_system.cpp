//
// Created by huxf on 2016/7/22.
//
#include <GL/glew.h>
#include <iostream>
#include "gl_render_system.h"
#include "glew_window.h"
#include "../../../Framework/log_manager.h"
#include "glcontext.h"

GLRenderSystem::GLRenderSystem()
{
}
//-----------------------------------------------------------------------
GLRenderSystem::~GLRenderSystem()
{
}
//-----------------------------------------------------------------------
const string &GLRenderSystem::getName() const
{
    static string name("OpenGL Rendering Subsystem");
    return name;
}
//-----------------------------------------------------------------------
shared_ptr<RenderWindow> GLRenderSystem::initialise(const string &windowTitle)
{
    float width = 500;
    float height = 500;

    shared_ptr<RenderWindow> window = make_shared<GLEWWindow>();
    window->Create(windowTitle, width, height);
    attachRenderTarget(window);

    initialiseContext(window);
    initGLEW();

    glViewport(0, 0, width, height);
    return window;
}
//-----------------------------------------------------------------------
void GLRenderSystem::initialiseContext(shared_ptr<RenderWindow> window)
{
    auto context = ((GLEWWindow*)window.get())->getContext();
    context->setCurrent();
}
//-----------------------------------------------------------------------
void GLRenderSystem::initGLEW()
{
    //必须在Context之后调用
    glewExperimental = GL_TRUE;
    if ( GLEW_OK != glewInit() )
    {
        Magic::LogManager::GetInstance().LogMessage("glew init Failed");
    }
}
//-----------------------------------------------------------------------
void GLRenderSystem::clearFrameBuffer(unsigned int buffers, const ColourValue &colour, float depth, unsigned short stencil)
{
    glClearColor(colour.r, colour.g, colour.b, colour.a);

    GLbitfield flags = 0;
    if(FBT_COLOUR & buffers)
    {
        flags |= GL_COLOR_BUFFER_BIT;
    }
    if(FBT_DEPTH & buffers)
    {
        flags |= GL_DEPTH_BUFFER_BIT;
    }
    if(FBT_STENCIL & buffers)
    {
        flags |= GL_STENCIL_BUFFER_BIT;
    }
    glClear(flags);
}
//-----------------------------------------------------------------------
void GLRenderSystem::render(const shared_ptr<RenderOperation> ro)
{
    RenderSystem::render(ro);

    bool useIndexes = false;
    bool hasInstanceData = true;
    if (useIndexes)
    {
        if(hasInstanceData)
        {
//            glDrawElementsInstanced();
        }
        else
        {
//            glDrawElements();
        }

    }
    else
    {
        if(hasInstanceData)
        {
//            glDrawArraysInstanced();
        }
        else
        {
//            glDrawArrays();
        }
    }
}
//-----------------------------------------------------------------------


