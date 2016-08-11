//
// Created by huxf on 2016/7/22.
//

#include <iostream>
#include "render_system.h"
#include "render_operation.h"

namespace Magic {

    RenderSystem::RenderSystem ()
    {
    }
    //-----------------------------------------------------------------------
    RenderSystem::~RenderSystem ()
    {
    }
    //-----------------------------------------------------------------------
    void RenderSystem::attachRenderTarget(shared_ptr<RenderTarget>target)
    {
        renderTargets_.insert(RenderTargetMap::value_type(target->getName(), target));
    }
    //-----------------------------------------------------------------------
    void RenderSystem::updateAllRenderTargets(bool swap)
    {
        for(auto target : renderTargets_)
        {
            target.second->update(swap);
        }
    }
    //-----------------------------------------------------------------------
    void RenderSystem::clearFrameBuffer(unsigned int buffers, const ColourValue &colour, float depth, unsigned short stencil)
    {
    }
    //-----------------------------------------------------------------------
    void RenderSystem::setViewMatrix(const glm::mat4 &vm)
    {
    }
    //-----------------------------------------------------------------------
    void RenderSystem::setProjectionMatrix(const glm::mat4 &pm)
    {
    }
    //-----------------------------------------------------------------------
    void RenderSystem::render(const shared_ptr<RenderOperation> ro)
    {
        //渲染统计
    }
    //-----------------------------------------------------------------------
    const string &RenderSystem::getName() const
    {
        static string name("Default Rendering Subsystem");
        return name;
    }
    //-----------------------------------------------------------------------
}