//
// Created by huxf on 2016/7/22.
//

#include "render_system.h"

RenderSystem::RenderSystem() {

}

RenderSystem::~RenderSystem() {

}

const string &RenderSystem::GetName() const {
    static string name("Default Rendering Subsystem");
    return name;
}


shared_ptr<RenderWindow> RenderSystem::Initialise(const string &windowTitle) {
    return nullptr;
}

