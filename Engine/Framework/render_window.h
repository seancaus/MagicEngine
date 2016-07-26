//
// Created by huxf on 2016/7/21.
//

#ifndef MAGICCUBE_RENDER_WINDOW_H
#define MAGICCUBE_RENDER_WINDOW_H

#include <GLFW/glfw3.h>
#include <string>
#include "object.h"
#include "camera.h"

class RenderWindow :public Object {

public:


    RenderWindow();
    virtual ~RenderWindow();

    virtual void CreateWindow(unsigned int width, unsigned int height,std::string& title);

    void AddViewport(Camera* camera);

protected:

    GLFWwindow*     window_;

};


#endif //MAGICCUBE_RENDER_WINDOW_H
