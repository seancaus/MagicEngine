//
// Created by huxf on 2016/7/22.
//
#include <GL/glew.h>
#include <iostream>
#include "gl_render_system.h"
#include "glew_window.h"
#include "../../../Framework/common.h"
#include "../../../Framework/log_manager.h"

GLRenderSystem::GLRenderSystem()
{
}

GLRenderSystem::~GLRenderSystem() {

}

const string &GLRenderSystem::GetName() const
{
    static string name("OpenGL Rendering Subsystem");
    return name;
}

shared_ptr<RenderWindow> GLRenderSystem::Initialise(const string &windowTitle)
{
    shared_ptr<RenderWindow> window = make_shared<GLEWWindow>();
    window->Create(windowTitle,500,500);

    InitGLEW();

//    glViewport(0, 0, w, h);

    AttachRenderTarget(window);
    return window;
}


void GLRenderSystem::InitGLEW()
{
    glewExperimental = GL_TRUE;
    if ( GLEW_OK != glewInit() )
    {
        Magic::LogManager::GetInstance().LogMessage("glew init Failed");
    }
}

void GLRenderSystem::ClearFrameBuffer(unsigned int buffers, const ColourValue &colour, float depth,
                                      unsigned short stencil)
{
    glClearColor(colour.r,colour.g,colour.b,colour.a);

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


void GLRenderSystem::Render(const shared_ptr<RenderOperation> ro)
{
    RenderSystem::Render(ro);

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
//            glDrawElements()
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
//            glDrawArrays()
        }
    }
}


