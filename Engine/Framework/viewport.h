//
// Created by huxf on 2016/8/3.
//

#ifndef MAGIC_VIEWPORT_H
#define MAGIC_VIEWPORT_H

#include "common.h"
#include "colour_value.h"

namespace magic
{
    class Camera;
    class RenderTarget;

    class Viewport
    {

    public:
        Viewport(Camera* camera, RenderTarget* target, float left, float top, float width, float height, int ZOrder);
        virtual ~Viewport();

        void update();
        void clear(unsigned int buffers = FBT_COLOUR | FBT_DEPTH, const ColourValue& colour = ColourValue::Black, float depth = 1.0f, unsigned short stencil = 0);

    protected:

        Camera*         camera_;
        RenderTarget*   target_;
        ColourValue     backColour_;
        int             zorder_;
        float relLeft_, relTop_, relWidth_, relHeight_;

    };
}

#endif //MAGIC_VIEWPORT_H
