//
// Created by huxf on 2016/8/3.
//

#include <iostream>
#include "camera.h"
#include "render_target.h"
#include "log_manager.h"

using namespace std;

namespace Magic {

    RenderTarget::RenderTarget()
    {
    }
    //-----------------------------------------------------------------------
    RenderTarget::~RenderTarget()
    {
    }
    //-----------------------------------------------------------------------
    const std::string &RenderTarget::getName(void) const
    {
        static string name("Default");
        return name;
    }
    //-----------------------------------------------------------------------
    void RenderTarget::update(bool swap)
    {
        _updateImpl();
        if (swap)
        {
            swapBuffers();
        }
    }
    //-----------------------------------------------------------------------
    Viewport* RenderTarget::addViewport(Camera *camera, int zorder, float left, float top, float width, float height)
    {
        //TODO
        auto it = viewports_.find(zorder);
        if( it != viewports_.end() )
        {
            LogManager::GetInstance().LogMessage("");
            return nullptr;
        }

        auto vp = make_shared<Viewport>(camera,this,left,top,width,height,zorder);
        viewports_.insert(ViewportList::value_type(zorder,vp));

        return vp.get();
    }
    //-----------------------------------------------------------------------
    void RenderTarget::removeViewport(int zorder)
    {
        auto it = viewports_.find(zorder);
        if( it != viewports_.end() )
        {
            viewports_.erase(zorder);
        }
    }
    //-----------------------------------------------------------------------
    void RenderTarget::removeAllViewports()
    {
        viewports_.clear();
    }
    //-----------------------------------------------------------------------
    void RenderTarget::_updateImpl()
    {
        _beginUpdate();
        _updateViewports();
        _endUpdate();
    }
    //-----------------------------------------------------------------------
    void RenderTarget::_updateViewports()
    {
        for(auto viewPort : viewports_)
        {
            auto vp  = viewPort.second;
            _updateViewport(vp);
        }
    }
    //-----------------------------------------------------------------------
    void RenderTarget::_updateViewport(shared_ptr<Viewport> viewport)
    {
        viewport->update();
    }
    //-----------------------------------------------------------------------
    void RenderTarget::_beginUpdate()
    {
    }
    //-----------------------------------------------------------------------
    void RenderTarget::_endUpdate()
    {

    }
    //-----------------------------------------------------------------------
    void RenderTarget::swapBuffers()
    {
        //TODO
    }
    //-----------------------------------------------------------------------
}




