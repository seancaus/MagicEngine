//
// Created by huxf on 2016/7/19.
//

#include "camera.h"
#include "scene_manager.h"

namespace magic {

    Camera::Camera(const string& name, SceneManager* sm):
        name_(name),
        sceneMgr_(sm)
    {

    }
    //-----------------------------------------------------------------------
    Camera::~Camera()
    {

    }
    //-----------------------------------------------------------------------
    void Camera::lookAt(float x, float y, float z)
    {
        Vector3 vtemp(x,y,z);
        lookAt(vtemp);
    }
    //-----------------------------------------------------------------------
    void Camera::lookAt(const Vector3 &targetPoint)
    {
        viewMatrix_ = glm::lookAt(glm::vec3(0,0,0),glm::vec3(0,0,0),glm::vec3(0,0,0));
    }
    //-----------------------------------------------------------------------
    glm::mat4 Camera::getViewMatrix()
    {
        return viewMatrix_;
    }
    //-----------------------------------------------------------------------
    void Camera::renderScene(Viewport *vp)
    {
        sceneMgr_->renderScene(this,vp);
    }
    //-----------------------------------------------------------------------
}

