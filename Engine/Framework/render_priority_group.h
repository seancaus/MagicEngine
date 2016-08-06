//
// Created by Ziv on 16/8/6.
//

#ifndef MAGIC_RENDER_PRIORITY_GROUP_H
#define MAGIC_RENDER_PRIORITY_GROUP_H

#include <memory>

using namespace std;

namespace Magic {

    class QueuedRenderableCollection;


    class RenderPriorityGroup
    {
    public:
        RenderPriorityGroup() ;
        virtual ~RenderPriorityGroup() ;

    protected:

        shared_ptr<QueuedRenderableCollection> basic_;

    };
}

#endif //MAGIC_RENDER_PRIORITY_GROUP_H
