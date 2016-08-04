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

        virtual void AddViewport(Camera* camera);
        virtual void SwapBuffers();
        virtual void Update(bool swap = true);


    protected:

        virtual void _UpdateImpl();
        virtual void _BeginUpdate();
        virtual void _UpdateViewports();
        virtual void _UpdateViewport(shared_ptr<Viewport> viewport);
        virtual void _EndUpdate();


        ViewportList viewports_;

    };
}
#endif //MAGIC_RENDER_TARGET_H
