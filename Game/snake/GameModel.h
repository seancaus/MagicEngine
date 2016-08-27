//
// Created by huxf on 2016/8/26.
//

#ifndef MAGIC_GAMEMODEL_H
#define MAGIC_GAMEMODEL_H

#include <memory>
#include "map.h"
#include "snake.h"
#include "food_manager.h"
#include <GLFW/glfw3.h>

using namespace std;

class GameModel
{

public:

    GameModel();
    virtual ~GameModel();

    void renderOneFrame();
    void onKeyCallback(GLFWwindow* window,int key,int scancode,int action,int mods);

protected:

    shared_ptr<Map>             _map;
    shared_ptr<Snake>           _snake;
    shared_ptr<FoodManager>     _foodManager;

};


#endif //MAGIC_GAMEMODEL_H
