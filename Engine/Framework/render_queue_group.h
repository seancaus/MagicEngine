//
// Created by Ziv on 16/8/6.
//

#ifndef MAGIC_RENDER_QUEUE_GROUP_H
#define MAGIC_RENDER_QUEUE_GROUP_H

#include <memory>
#include <map>

using namespace std;

namespace Magic
{

    class RenderPriorityGroup;

    typedef map<unsigned short,shared_ptr<RenderPriorityGroup>> PriorityMap;

    class RenderQueueGroup
    {

    public:

        RenderQueueGroup();
        virtual ~RenderQueueGroup();

    protected:

        PriorityMap priorityGroups_;

    };

}

#endif //MAGIC_RENDER_QUEUE_GROUP_H
