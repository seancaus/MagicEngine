//
// Created by Ziv on 16/8/6.
//

#include "render_queue_group.h"
#include "renderable.h"
#include "render_priority_group.h"

namespace Magic
{

    RenderQueueGroup::RenderQueueGroup() {

    }
    //-----------------------------------------------------------------------
    RenderQueueGroup::~RenderQueueGroup() {

    }
    //-----------------------------------------------------------------------
    void RenderQueueGroup::addRenderable(shared_ptr<Renderable>pRend, void *pTech, unsigned short priority)
    {
        shared_ptr<RenderPriorityGroup> pPriorityGrp = nullptr;
        auto i = priorityGroups_.find(priority);
        if( i == priorityGroups_.end() )
        {
            pPriorityGrp = make_shared<RenderPriorityGroup>();
            priorityGroups_.insert(PriorityGroupMap::value_type(priority,pPriorityGrp));
        }
        else
        {
            pPriorityGrp = i->second;
        }

        pPriorityGrp->addRenderable(pRend,pTech);
    }
    //-----------------------------------------------------------------------

}