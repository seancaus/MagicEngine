//
// Created by huxf on 2016/7/19.
//

#include "camera.h"
#include "scene_manager.h"

namespace Magic {

    Camera::Camera() :
    sceneMgr_(nullptr)
    {

    }

    Camera::~Camera() {

    }


    void Camera::LookAt() {

    }


    void Camera::RenderScene(Viewport *vp, bool includeOverlays)
    {
        sceneMgr_->RenderScene(this,vp,includeOverlays);
    }

}

