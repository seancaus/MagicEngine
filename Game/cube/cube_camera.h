//
// Created by huxf on 2016/8/29.
//

#ifndef MAGIC_CUBE_CAMERA_H
#define MAGIC_CUBE_CAMERA_H

#include <glm/glm.hpp>
#include "../../Engine/Framework/vector3.h"

using namespace magic;

class CubeCamera
{

public:

    CubeCamera();
    virtual ~CubeCamera();

    void setPosition(glm::vec3 position);
    glm::vec3 getPosition();
    void lookAt(glm::vec3 target);
    glm::mat4 getViewMatrix();
    glm::vec3 getDirection();


protected:

    glm::vec3 _position;
    glm::vec3 _cameraTarget;

};


#endif //MAGIC_CUBE_CAMERA_H
