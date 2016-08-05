//
// Created by huxf on 2016/8/4.
//

#ifndef MAGIC_RENDER_QUEUE_H
#define MAGIC_RENDER_QUEUE_H

#include <map>
#include <memory>

using namespace std;

namespace Magic {

//    typedef map< uint8, RenderQueueGroup* > RenderQueueGroupMap;
    class MovableObject;
    class Camera;

    class RenderQueue {

    public:

        RenderQueue();
        virtual ~RenderQueue();

        virtual void ProcessVisibleObject(shared_ptr<MovableObject> mo, shared_ptr<Camera> ca);

    protected:



    };

}
#endif //MAGIC_RENDER_QUEUE_H
