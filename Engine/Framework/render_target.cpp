//
// Created by huxf on 2016/8/3.
//

#include "camera.h"
#include "render_target.h"

using namespace std;

namespace Magic {

    RenderTarget::RenderTarget()
    {

    }

    RenderTarget::~RenderTarget()
    {

    }

    const std::string &RenderTarget::getName(void) const
    {
        static string name("Default");
        return name;
    }

    void RenderTarget::Update(bool swap)
    {
        _UpdateImpl();

        if (swap)
        {
            SwapBuffers();
        }
    }

    void RenderTarget::AddViewport(Camera *camera)
    {

    }

    void RenderTarget::_UpdateImpl()
    {
        _BeginUpdate();
        _UpdateViewports();
        _EndUpdate();
    }

    void RenderTarget::_BeginUpdate() {

    }

    void RenderTarget::_UpdateViewports()
    {
        for(auto viewPort : viewports_)
        {
            auto vp  = viewPort.second;
            _UpdateViewport(vp);
        }
    }

    void RenderTarget::_UpdateViewport(shared_ptr<Viewport> viewport)
    {
        viewport->Update();
    }

    void RenderTarget::_EndUpdate() {

    }

    void RenderTarget::SwapBuffers()
    {

    }
}




