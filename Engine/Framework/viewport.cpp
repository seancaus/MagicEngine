//
// Created by huxf on 2016/8/3.
//

#include "viewport.h"
#include "camera.h"
#include "render_target.h"


namespace Magic
{

    Viewport::Viewport(Camera *camera, RenderTarget *target, float left, float top, float width, float height, int ZOrder):
    camera_(camera)
    {

    }

    Viewport::~Viewport()
    {

    }

    void Viewport::Update(void)
    {
        camera_->RenderScene(this,true);
    }

    void Viewport::Clear(unsigned int buffers, const ColourValue &colour, float depth, unsigned short stencil)
    {

    }

}