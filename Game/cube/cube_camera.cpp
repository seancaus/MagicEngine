//
// Created by huxf on 2016/8/29.
//

#include "cube_camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

CubeCamera::CubeCamera() {

}

CubeCamera::~CubeCamera() {

}


void CubeCamera::setPosition(glm::vec3 position)
{
    _position = position;
}

glm::vec3 CubeCamera::getPosition()
{
    return _position;
}

void CubeCamera::lookAt(glm::vec3 target)
{
//    _view = glm::lookAt(glm::vec3(300.0f, 0.0f, 500.0f),
//                        glm::vec3(0.0f, 0.0f, 0.0f),
//                        glm::vec3(0.0f, 1.0f, 0.0f));

    _cameraTarget = target;
}


glm::mat4 CubeCamera::getViewMatrix()
{
    return glm::lookAt(_position, _cameraTarget ,glm::vec3(0.0f, 1.0f, 0.0f));
}


glm::vec3 CubeCamera::getDirection()
{
    return glm::normalize(_cameraTarget - _position);
}