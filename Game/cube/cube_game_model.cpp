//
// Created by huxf on 2016/8/29.
//

#include "cube_game_model.h"

CubeGameModel::CubeGameModel()
{
    _camera = make_shared<CubeCamera>();
    _camera->setPosition(glm::vec3(.0f,.0f,500.0f));
    _camera->lookAt(glm::vec3(.0f,.0f,.0f));

    memset(_keys,0, sizeof(_keys));
    _cube = make_shared<Cube>(_camera);
    _cube->preBind();
}

CubeGameModel::~CubeGameModel()
{

}

void CubeGameModel::renderOneFrame()
{
    movement();
    _cube->draw();
}


void CubeGameModel::movement()
{
    auto dir = _camera->getDirection();

    dir *= 0.08;
    if(_keys[GLFW_KEY_W])
    {
        auto newPos = _camera->getPosition() + dir;
        _camera->setPosition(newPos);
    }
    if(_keys[GLFW_KEY_S])
    {
        auto newPos = _camera->getPosition() - dir;
        _camera->setPosition(newPos);
    }
    if(_keys[GLFW_KEY_A])
    {
        auto newPos = _camera->getPosition() - glm::cross(glm::vec3(.0f,1.0f,.0f),dir);
        _camera->setPosition(newPos);
    }
    if(_keys[GLFW_KEY_D])
    {
        auto newPos = _camera->getPosition() +glm::cross(glm::vec3(.0f,1.0f,.0f),dir);
        _camera->setPosition(newPos);
    }

    int keyNames[] = {GLFW_KEY_A , GLFW_KEY_W , GLFW_KEY_S , GLFW_KEY_D};
    for(auto name:keyNames)
    {
        if(_keys[name]) {
            _cube->updateCamera();
            break;
        }
    }
}

void CubeGameModel::onKeyCallback(GLFWwindow *window, int key, int scanCode, int action, int mode)
{
    if(GLFW_KEY_A != key && GLFW_KEY_W != key&& GLFW_KEY_S != key&& GLFW_KEY_D != key)
    {
        return;
    }

    if( GLFW_PRESS == action )
    {
        _keys[key] = true;
    }else if (GLFW_RELEASE == action )
    {
        _keys[key] = false;
    }


}

void CubeGameModel::onMouseMoveCallback(GLFWwindow *window, double xpos, double ypos)
{
    _cube->onMouseMove(xpos,ypos);
}