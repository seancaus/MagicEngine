//
// Created by huxf on 2016/8/4.
//

#ifndef MAGIC_RENDER_QUEUE_H
#define MAGIC_RENDER_QUEUE_H

#include <map>

using namespace std;

namespace Magic {

//    typedef map< uint8, RenderQueueGroup* > RenderQueueGroupMap;

    class RenderQueue {

    public:

        RenderQueue();
        virtual ~RenderQueue();

    };

}
#endif //MAGIC_RENDER_QUEUE_H
