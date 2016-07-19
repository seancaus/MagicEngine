//
// Created by Ziv on 16/7/19.
//

#include <iostream>
#include <algorithm>
#include "../Engine/Framework/panel.h"
#include "cube_game_mode.h"

using namespace std;

static int cube_width = 3;
CubeGameMode::CubeGameMode():
        GameMode()
{
    int size = cube_width * cube_width;
    glm::vec4 colors[6] = {{1,1,1,.5},{1,0,0,1},{0,1,0,1},{0,0,1,1},{.3,0,0,1},{0,.5,0,1}};

    int w = 40;
    for(int i = 0;i < 1;++i)
    {
        int start_x = 300;
        int start_y = 200;
        for (int j = 0; j < size; ++j) {
            shared_ptr<Panel> ptr = make_shared<Panel>();
            ptr->color_ = colors[i];
            ptr->size_ = {w,w,0};

            int col = j % cube_width;
            int row = j / cube_width;
            int x = start_x + col * w + col;
            int y = start_y + row * w + row;
            cout << "x:" << x << "y:"<< y<< endl;
            ptr->transform_.translation = {x,y,0};

            ptr->preBind();

            panels.push_back(ptr);
        }
    }
}

void CubeGameMode::MainLoop()
{
    for_each(panels.cbegin(),panels.cend(),[](const shared_ptr<Panel>& panel)-> void{
        panel->draw();
    });
}