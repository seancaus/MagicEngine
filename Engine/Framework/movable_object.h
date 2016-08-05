//
// Created by huxf on 2016/7/26.
//

#ifndef MAGICCUBE_MOVABLE_OBJECT_H
#define MAGICCUBE_MOVABLE_OBJECT_H

#include <string>
#include <memory>
#include "node.h"

using namespace std;

namespace Magic
{


    class RenderQueue;

    class MovableObject
    {

    public:

        MovableObject();
        virtual ~MovableObject();

        void UpdateRenderQueue(shared_ptr<RenderQueue> queue);

    protected:

        string  name_;
        Node*   parentNode_;
        bool    visible_;

    };
}
#endif //MAGICCUBE_MOVABLE_OBJECT_H
