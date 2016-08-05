//
// Created by huxf on 2016/8/4.
//

#include "render_queue.h"
#include "movable_object.h"

namespace Magic {

    RenderQueue::RenderQueue() {

    }

    RenderQueue::~RenderQueue() {

    }

    void RenderQueue::ProcessVisibleObject(shared_ptr<MovableObject> mo, shared_ptr<Camera> ca)
    {

        mo->UpdateRenderQueue(shared_ptr<RenderQueue>(this));
    }

}
