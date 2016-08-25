//
// Created by huxf on 2016/7/22.
//

#ifndef MAGICCUBE_GL_RENDER_SYSTEM_H
#define MAGICCUBE_GL_RENDER_SYSTEM_H

#include "../../../Framework/render_system.h"

using namespace magic;

class GLRenderSystem : public RenderSystem
{

public:
    GLRenderSystem();
    virtual ~GLRenderSystem();

    virtual shared_ptr<RenderWindow> initialise(const string &windowTitle) override;

    virtual void clearFrameBuffer(unsigned int buffers, const ColourValue &colour, float depth, unsigned short stencil) override;
    virtual void render(const shared_ptr<RenderOperation> ro) override;

    virtual const string &getName() const override;

protected:

    virtual void initialiseContext(shared_ptr<RenderWindow> window);
    virtual void initGLEW();

};


#endif //MAGICCUBE_GL_RENDER_SYSTEM_H
