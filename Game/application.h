//
// Created by huxf on 2016/7/19.
//

#ifndef MAGICCUBE_APPLICATION_H
#define MAGICCUBE_APPLICATION_H

#include <GLFW/glfw3.h>
#include "../Engine/Framework/object.h"

class GameMode;

class Application :public Object
{
public:

    virtual ~Application();
    static Application& GetInstance();

    int Run();
    void Close();

protected:

    GameMode*       game_mode_;
    GLFWwindow*     window_;

private:
    Application();

    static Application* instance;
};


#endif //MAGICCUBE_APPLICATION_H
