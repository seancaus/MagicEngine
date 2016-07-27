//
// Created by huxf on 2016/7/21.
//

#ifndef MAGICCUBE_RENDER_WINDOW_H
#define MAGICCUBE_RENDER_WINDOW_H

#include <string>
#include "object.h"
#include "camera.h"
#include "magic_platform.h"

using namespace std;

class RenderWindow :public Object {

public:

    RenderWindow();
    virtual ~RenderWindow();
    virtual void Destroy() = 0;

    virtual void Create(const string& windowTitle, unsigned int width, unsigned int height);
    virtual void AddViewport(Camera* camera);

};


#endif //MAGICCUBE_RENDER_WINDOW_H
