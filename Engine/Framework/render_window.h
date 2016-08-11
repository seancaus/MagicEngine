//
// Created by huxf on 2016/7/21.
//

#ifndef MAGICCUBE_RENDER_WINDOW_H
#define MAGICCUBE_RENDER_WINDOW_H

#include <string>
#include "camera.h"
#include "render_target.h"
#include "magic_platform.h"

using namespace std;

namespace Magic {

    class RenderWindow : public RenderTarget {

    public:
        RenderWindow();
        virtual ~RenderWindow();

        virtual void Create(const string &windowTitle, unsigned int width, unsigned int height) = 0;
        virtual void Destroy() = 0;
    };
}
#endif //MAGICCUBE_RENDER_WINDOW_H
