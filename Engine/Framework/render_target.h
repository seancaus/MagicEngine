//
// Created by huxf on 2016/8/3.
//

#ifndef MAGIC_RENDER_TARGET_H
#define MAGIC_RENDER_TARGET_H

#include <map>
#include <string>
#include <memory>
#include "object.h"
#include "viewport.h"

using namespace std;

namespace Magic
{
    class Camera;

    typedef map<int, shared_ptr<Viewport>> ViewportList;

    class RenderTarget :public Object
    {

    public:

        RenderTarget();
        virtual ~RenderTarget();

        virtual const std::string& getName(void) const;

        virtual Viewport* addViewport(Camera* camera, int ZOrder = 0, float left = 0.0f, float top = 0.0f, float width = 1.0f, float height = 1.0f);
        virtual void removeViewport(int zorder);
        virtual void removeAllViewports();

        virtual void swapBuffers();
        virtual void update(bool swap = true);


    protected:

        virtual void _updateImpl();
        virtual void _beginUpdate();
        virtual void _updateViewports();
        virtual void _updateViewport(shared_ptr<Viewport> viewport);
        virtual void _endUpdate();


        ViewportList viewports_;

    };
}
#endif //MAGIC_RENDER_TARGET_H
