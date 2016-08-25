//
// Created by huxf on 2016/8/3.
//

#include "viewport.h"
#include "camera.h"
#include "render_target.h"


namespace magic
{

    Viewport::Viewport(Camera *camera, RenderTarget *target, float left, float top, float width, float height, int ZOrder):
        camera_(camera),
        target_(target),
        relLeft_(left),
        relTop_(top),
        relWidth_(width),
        relHeight_(height),
        zorder_(ZOrder),

        backColour_(ColourValue::Black)
    {

    }
    //-----------------------------------------------------------------------
    Viewport::~Viewport()
    {

    }
    //-----------------------------------------------------------------------
    void Viewport::update(void)
    {
        if( camera_ )
        {
            camera_->renderScene(this);
        }
    }
    //-----------------------------------------------------------------------
    void Viewport::clear(unsigned int buffers, const ColourValue &colour, float depth, unsigned short stencil)
    {

    }
    //-----------------------------------------------------------------------
}