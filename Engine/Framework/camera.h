//
// Created by huxf on 2016/7/19.
//

#ifndef MAGICCUBE_CAMERA_H
#define MAGICCUBE_CAMERA_H

#include "object.h"
#include "Viewport.h"

namespace Magic {

    class Camera : public Object {
    public:

        Camera();
        virtual ~Camera();

        void LookAt();
        void RenderScene(Viewport *vp, bool includeOverlays);

    protected:


    private:

    };
}

#endif //MAGICCUBE_CAMERA_H
