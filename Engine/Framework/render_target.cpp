//
// Created by huxf on 2016/8/3.
//

#include "render_target.h"
#include <string>

using namespace std;

namespace Magic {

    RenderTarget::RenderTarget() {

    }


    RenderTarget::~RenderTarget() {

    }

    const std::string &RenderTarget::getName(void) const {
        static string name("Default");
        return name;
    }


    void RenderTarget::Update(bool swapBuffers) {
        UpdateImpl();

        if (swapBuffers) {
            SwapBuffers();
        }
    }

    void RenderTarget::AddViewport(Camera *camera) {

    }

    void RenderTarget::UpdateImpl() {

    }

    void RenderTarget::SwapBuffers() {

    }
}




