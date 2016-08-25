//
// Created by huxf on 2016/7/26.
//

#ifndef MAGICCUBE_MOVABLE_OBJECT_H
#define MAGICCUBE_MOVABLE_OBJECT_H

#include <string>
#include <memory>
#include "node.h"

using namespace std;

namespace magic
{
    class RenderQueue;

    class MovableObject
    {

    public:

        MovableObject();
        virtual ~MovableObject();

        void updateRenderQueue(RenderQueue* queue);


        const string &getName() const {
            return name_;
        }

        Node *getParentNode() const {
            return parentNode_;
        }

        bool isVisible() const {
            return visible_;
        }

    protected:

        string  name_;
        Node*   parentNode_;
        bool    visible_;

    };
}
#endif //MAGICCUBE_MOVABLE_OBJECT_H
