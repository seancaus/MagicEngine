//
// Created by huxf on 2016/7/22.
//

#ifndef MAGICCUBE_RENDER_SYSTEM_H
#define MAGICCUBE_RENDER_SYSTEM_H

#include <string>
#include <memory>
#include "render_window.h"

using namespace std;

class RenderSystem
{

public:
    RenderSystem() ;
    virtual ~RenderSystem() ;

    virtual const string& GetName()const;
    virtual shared_ptr<RenderWindow> Initialise(const string& windowTitle);

};


#endif //MAGICCUBE_RENDER_SYSTEM_H
