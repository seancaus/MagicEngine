//
// Created by Ziv on 16/7/19.
//

#ifndef MAGICCUBE_CUBE_GAME_MODE_H
#define MAGICCUBE_CUBE_GAME_MODE_H

#include <memory>
#include <vector>
#include "../Engine/Framework/game_mode.h"

using namespace std;

class Panel;

class CubeGameMode :public  GameMode{

public:
    CubeGameMode();

    virtual void MainLoop() override ;

protected:


private:

    vector<std::shared_ptr<Panel> >panels;
};

#endif //MAGICCUBE_CUBE_GAME_MODE_H