//
// Created by huxf on 2016/7/22.
//

#ifndef MAGICCUBE_GL_RENDER_SYSTEM_H
#define MAGICCUBE_GL_RENDER_SYSTEM_H

#include "../../../Framework/render_system.h"

class GLRenderSystem : public RenderSystem
{

public:
    GLRenderSystem();
    virtual ~GLRenderSystem();

    virtual const string &GetName() const override ;

    virtual shared_ptr<RenderWindow> Initialise(const string &windowTitle) override ;


};


#endif //MAGICCUBE_GL_RENDER_SYSTEM_H
