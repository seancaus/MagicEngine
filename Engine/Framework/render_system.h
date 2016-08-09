//
// Created by huxf on 2016/7/22.
//

#ifndef MAGICCUBE_RENDER_SYSTEM_H
#define MAGICCUBE_RENDER_SYSTEM_H

#include <string>
#include <memory>
#include <map>
#include <glm/detail/type_mat.hpp>
#include "render_window.h"
#include "colour_value.h"

using namespace std;

namespace Magic {

    class RenderOperation;

    typedef map< string, shared_ptr<RenderTarget>> RenderTargetMap;

    class RenderSystem {

    public:
        RenderSystem();

        virtual ~RenderSystem();

        virtual const string &GetName() const;

        virtual shared_ptr<RenderWindow> Initialise(const string &windowTitle) = 0;

        virtual void AttachRenderTarget(shared_ptr<RenderTarget> target);
        virtual void UpdateAllRenderTargets(bool swap);
        virtual void ClearFrameBuffer(unsigned int buffers, const ColourValue& colour, float depth, unsigned short stencil);

        virtual void SetViewMatrix(const glm::mat4& vm);
        virtual void SetProjectionMatrix(const glm::mat4& pm);

        virtual void Render(const shared_ptr<RenderOperation> ro);

    protected:

        RenderTargetMap renderTargets_;

    };
}


#endif //MAGICCUBE_RENDER_SYSTEM_H
