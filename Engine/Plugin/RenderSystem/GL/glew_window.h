//
// Created by huxf on 2016/7/27.
//

#ifndef MAGIC_GLEW_WINDOW_H
#define MAGIC_GLEW_WINDOW_H

#include <GLFW/glfw3.h>
#include "../../../Framework/render_window.h"

using namespace Magic;

class GLEWWindow : public RenderWindow
{

public:

    GLEWWindow();
    virtual ~GLEWWindow();

    virtual void init();
    virtual void Destroy() override;
    virtual void Create(const string &title, unsigned int width, unsigned int height) override;

    virtual void SwapBuffers() override;
    virtual void AddViewport(Camera *camera) override;

    virtual const std::string &getName(void) const override;
    virtual void getWindowSize();

protected:

    GLFWwindow*     window_;
};


#endif //MAGIC_GLEW_WINDOW_H
