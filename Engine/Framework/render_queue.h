//
// Created by huxf on 2016/8/4.
//

#ifndef MAGIC_RENDER_QUEUE_H
#define MAGIC_RENDER_QUEUE_H

#include <map>
#include <memory>

using namespace std;

namespace Magic {

    enum RenderQueueGroupID
    {
        RENDER_QUEUE_BACKGROUND = 0,
        RENDER_QUEUE_OVERLAY = 100,
    };

    class MovableObject;
    class Camera;
    class RenderQueueGroup;

    typedef map<RenderQueueGroupID, RenderQueueGroup* > RenderQueueGroupMap;

    class RenderQueue
    {

    public:

        RenderQueue();
        virtual ~RenderQueue();

        virtual void ProcessVisibleObject(shared_ptr<MovableObject> mo, shared_ptr<Camera> ca);

    protected:

        RenderQueueGroupMap renderGroups_;

    };

}
#endif //MAGIC_RENDER_QUEUE_H
