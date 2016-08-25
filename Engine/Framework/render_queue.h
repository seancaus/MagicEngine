//
// Created by huxf on 2016/8/4.
//

#ifndef MAGIC_RENDER_QUEUE_H
#define MAGIC_RENDER_QUEUE_H

#include <map>
#include <memory>


using namespace std;

namespace magic {

    enum RenderQueueGroupID
    {
        RENDER_QUEUE_BACKGROUND = 0,
        RENDER_QUEUE_OVERLAY = 100,
    };

    class Camera;
    class Renderable;
    class RenderQueueGroup;
    class MovableObject;

    typedef map<RenderQueueGroupID, shared_ptr<RenderQueueGroup>> RenderQueueGroupMap;

    class RenderQueue
    {

    public:

        RenderQueue();
        virtual ~RenderQueue();

        void processVisibleObject(MovableObject* mo, Camera* ca);
        void addRenderable(shared_ptr<Renderable> rend, RenderQueueGroupID groupID, unsigned short priority);
        RenderQueueGroup* getQueueGroup(RenderQueueGroupID groupID);

    protected:

        RenderQueueGroupMap groups_;

    };

}
#endif //MAGIC_RENDER_QUEUE_H
