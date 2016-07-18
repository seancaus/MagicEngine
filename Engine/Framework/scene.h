//
// Created by Ziv on 16/7/16.
//

#ifndef MAGICCUBE_SCENE_H
#define MAGICCUBE_SCENE_H

#include "object.h"

class Scene :public Object{

public:
    Scene();
    virtual ~Scene();

    virtual void init();
    virtual void onEnter();
    virtual void onExit();
};


#endif //MAGICCUBE_SCENE_H
