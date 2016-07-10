//
// Created by Ziv on 16/7/10.
//

#ifndef MAGICCUBE_APPLICATION_H
#define MAGICCUBE_APPLICATION_H

#include <GLFW/glfw3.h>

class Application {

public:
    virtual ~Application();

    static Application& getInstance();

    int run();
    void close();

protected:
    static Application* application;

    GLFWwindow* _window;

private:

    Application();

};


#endif //MAGICCUBE_APPLICATION_H
