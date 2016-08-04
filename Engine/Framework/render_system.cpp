//
// Created by huxf on 2016/7/22.
//

#include <iostream>
#include "render_system.h"

namespace Magic {

    RenderSystem::RenderSystem ()
    {

    }

    RenderSystem::~RenderSystem ()
    {

    }

    const string &RenderSystem::GetName() const
    {
        static string name("Default Rendering Subsystem");
        return name;
    }

    void RenderSystem::AttachRenderTarget(shared_ptr<RenderTarget>target)
    {
        renderTargets_.insert(RenderTargetMap::value_type(target->getName(), target));
    }

    void RenderSystem::UpdateAllRenderTargets(bool swap)
    {
        for(auto target : renderTargets_)
        {
            target.second->Update(swap);
        }
    }

    void RenderSystem::ClearFrameBuffer(unsigned int buffers, const ColourValue &colour, float depth,
                                        unsigned short stencil)
    {

    }

}