//
// Created by huxf on 2016/7/22.
//

#ifndef MAGICCUBE_RENDER_SYSTEM_H
#define MAGICCUBE_RENDER_SYSTEM_H

#include <string>
#include <memory>
#include <map>
#include "render_window.h"
#include "colour_value.h"

using namespace std;

namespace Magic {

    typedef map< string, shared_ptr<RenderTarget>> RenderTargetMap;

    class RenderSystem {

    public:
        RenderSystem();

        virtual ~RenderSystem();

        virtual const string &GetName() const;

        virtual shared_ptr<RenderWindow> Initialise(const string &windowTitle) = 0;

        virtual void AttachRenderTarget(shared_ptr<RenderTarget> target);
        virtual void UpdateAllRenderTargets(bool swapBuffers);
        virtual void ClearFrameBuffer(unsigned int buffers, const ColourValue& colour, float depth, unsigned short stencil);

    protected:

        RenderTargetMap renderTargets_;

    };
}


#endif //MAGICCUBE_RENDER_SYSTEM_H
