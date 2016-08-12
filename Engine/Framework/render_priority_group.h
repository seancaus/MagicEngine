//
// Created by Ziv on 16/8/6.
//

#ifndef MAGIC_RENDER_PRIORITY_GROUP_H
#define MAGIC_RENDER_PRIORITY_GROUP_H

#include <memory>

#include "queued_renderable_collection.h"

using namespace std;

namespace Magic {

    class Renderable;

    class RenderPriorityGroup
    {
    public:
        RenderPriorityGroup() ;
        virtual ~RenderPriorityGroup();

        virtual void addRenderable(shared_ptr<Renderable> pRend, void* pTech);
    protected:

        QueuedRenderableCollection basic_;

    };
}

#endif //MAGIC_RENDER_PRIORITY_GROUP_H
