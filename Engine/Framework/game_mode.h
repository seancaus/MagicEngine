//
// Created by Ziv on 16/7/10.
//

#ifndef MAGICCUBE_APPLICATION_H
#define MAGICCUBE_APPLICATION_H

#include <GLFW/glfw3.h>
#include "object.h"

class GameMode :public Object{

public:
    virtual ~GameMode();

    static GameMode& getInstance();

    int Run();
    void Close();

    void LoadConfig();

protected:
    GameMode();

    static GameMode* instance;

    GLFWwindow* window_;

};


#endif //MAGICCUBE_APPLICATION_H
