//
// Created by huxf on 2016/8/26.
//

#include "GameModel.h"


GameModel::GameModel()
{
    _map = make_shared<Map>();
    _snake = make_shared<Snake>();
    _foodManager = make_shared<FoodManager>();

    _map->preBind();
    _snake->preBind();
    _foodManager->preBind();
}

GameModel::~GameModel()
{

}


void GameModel::onKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if(action != GLFW_PRESS) return;

    if(key == GLFW_KEY_UP)
    {
        _snake->setForward(true);
    }else if(key == GLFW_KEY_DOWN)
    {
        _snake->setForward(false);
    }else if(key == GLFW_KEY_LEFT)
    {
        _snake->setRight(false);
    }
    else if(key == GLFW_KEY_RIGHT)
    {
        _snake->setRight(true);
    }
}

void GameModel::renderOneFrame()
{
    _map->draw();
    _foodManager->draw();
    _snake->move();
    _snake->draw();

}
