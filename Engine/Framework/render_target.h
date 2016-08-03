//
// Created by huxf on 2016/8/3.
//

#ifndef MAGIC_RENDER_TARGET_H
#define MAGIC_RENDER_TARGET_H

#include <string>
#include "object.h"
#include "camera.h"

namespace Magic
{
    class RenderTarget :public Object
    {

    public:

        RenderTarget();
        virtual ~RenderTarget();

        virtual const std::string& getName(void) const;

        virtual void AddViewport(Camera* camera);
        virtual void SwapBuffers();
        virtual void Update(bool swapBuffers = true);

    protected:

        virtual void UpdateImpl();


    };
}
#endif //MAGIC_RENDER_TARGET_H
