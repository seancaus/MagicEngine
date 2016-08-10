//
// Created by huxf on 2016/7/19.
//

#include "camera.h"
#include "scene_manager.h"

namespace Magic {

    Camera::Camera(const string& name, SceneManager* sm):
        name_(name),
        sceneMgr_(sm)
    {

    }

    Camera::~Camera()
    {

    }

    void Camera::LookAt(float x, float y, float z)
    {
        Vector3 vtemp(x,y,z);
        LookAt(vtemp);
    }

    void Camera::LookAt(const Vector3 &targetPoint)
    {
        viewMatrix_ = glm::lookAt(glm::vec3(0,0,0),glm::vec3(0,0,0),glm::vec3(0,0,0));
    }

    glm::mat4 Camera::getViewMatrix()
    {
        return viewMatrix_;
    }

    void Camera::RenderScene(Viewport *vp, bool includeOverlays)
    {
        sceneMgr_->RenderScene(this,vp,includeOverlays);
    }

}

