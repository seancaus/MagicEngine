//
// Created by Ziv on 16/7/10.
//

#ifndef MAGICCUBE_GAMEMODE_H
#define MAGICCUBE_GAMEMODE_H

#include <GLFW/glfw3.h>
#include "object.h"

class GameMode :public Object{

public:
    GameMode();
    virtual ~GameMode();

    virtual void MainLoop();

protected:

};

#endif //MAGICCUBE_GAMEMODE_H
