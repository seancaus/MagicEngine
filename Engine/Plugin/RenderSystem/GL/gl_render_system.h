//
// Created by huxf on 2016/7/22.
//

#ifndef MAGICCUBE_GL_RENDER_SYSTEM_H
#define MAGICCUBE_GL_RENDER_SYSTEM_H

#include "../../../Framework/render_system.h"

using namespace Magic;

class GLRenderSystem : public RenderSystem
{

public:
    GLRenderSystem();
    virtual ~GLRenderSystem();

    virtual const string &GetName() const override;

    virtual shared_ptr<RenderWindow> Initialise(const string &windowTitle) override ;

    virtual void ClearFrameBuffer(unsigned int buffers, const ColourValue &colour, float depth,
                                  unsigned short stencil) override ;

protected:
    void InitGLEW();

};


#endif //MAGICCUBE_GL_RENDER_SYSTEM_H
