//
// Created by huxf on 2016/8/4.
//

#include "render_queue.h"
#include "movable_object.h"
#include "render_queue_group.h"

namespace Magic {

    RenderQueue::RenderQueue() {

    }
    //-----------------------------------------------------------------------
    RenderQueue::~RenderQueue() {

    }
    //-----------------------------------------------------------------------
    void RenderQueue::processVisibleObject(MovableObject* mo, Camera* ca)
    {
        mo->UpdateRenderQueue(this);
    }
    //-----------------------------------------------------------------------

    void RenderQueue::addRenderable(shared_ptr<Renderable> rend, RenderQueueGroupID groupID, unsigned short priority)
    {

    }
    //-----------------------------------------------------------------------
    RenderQueueGroup *RenderQueue::getQueueGroup(RenderQueueGroupID groupID)
    {
        shared_ptr<RenderQueueGroup> group = nullptr;
        auto groupIt = groups_.find(groupID);
        if ( groupIt == groups_.end() )
        {
            group = make_shared<RenderQueueGroup>();
            groups_.insert(RenderQueueGroupMap::value_type(groupID, group));
        }
        else
        {
            group = groupIt->second;
        }
        return group.get();
    }
    //-----------------------------------------------------------------------
}
