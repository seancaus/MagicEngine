//
// Created by huxf on 2016/7/22.
//
#include <iostream>
#include "gl_render_system.h"
#include "glew_window.h"

GLRenderSystem::GLRenderSystem() {

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
    return window;
}

