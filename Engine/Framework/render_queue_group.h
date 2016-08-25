//
// Created by Ziv on 16/8/6.
//

#ifndef MAGIC_RENDER_QUEUE_GROUP_H
#define MAGIC_RENDER_QUEUE_GROUP_H

#include <memory>
#include <map>

using namespace std;

namespace magic
{
    class Renderable;
    class RenderPriorityGroup;

    typedef map<unsigned short,shared_ptr<RenderPriorityGroup>> PriorityGroupMap;

    class RenderQueueGroup
    {

    public:

        RenderQueueGroup();
        virtual ~RenderQueueGroup();

        virtual void addRenderable(shared_ptr<Renderable> pRend, void* pTech, unsigned short priority);

    protected:

        PriorityGroupMap priorityGroups_;

    };

}

#endif //MAGIC_RENDER_QUEUE_GROUP_H
