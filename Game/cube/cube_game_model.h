//
// Created by huxf on 2016/8/29.
//

#ifndef MAGIC_CUBE_GAME_MODEL_H
#define MAGIC_CUBE_GAME_MODEL_H

#include "cube.h"
#include "cube_camera.h"
#include <GLFW/glfw3.h>


class CubeGameModel
{
public:
    CubeGameModel();
    virtual ~CubeGameModel();

    void renderOneFrame();
    void movement();

    void onKeyCallback(GLFWwindow* window,int key,int scanCode,int action,int mode);
    void onMouseMoveCallback(GLFWwindow* window,double xpos,double ypos);
protected:


    shared_ptr<Cube> _cube;
    shared_ptr<CubeCamera> _camera;

    bool _keys[1024];
};


#endif //MAGIC_CUBE_GAME_H
