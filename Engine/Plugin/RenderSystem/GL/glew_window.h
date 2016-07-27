//
// Created by huxf on 2016/7/27.
//

#ifndef MAGIC_GLEW_WINDOW_H
#define MAGIC_GLEW_WINDOW_H

#include <GLFW/glfw3.h>
#include "../../../Framework/render_window.h"

class GLEWWindow : public RenderWindow
{

public:

    GLEWWindow();
    virtual ~GLEWWindow();

    virtual void Destroy() override;
    virtual void Create(const string &title, unsigned int width, unsigned int height) override;
    virtual void AddViewport(Camera *camera) override;

protected:

    GLFWwindow*     window_;
};


#endif //MAGIC_GLEW_WINDOW_H
