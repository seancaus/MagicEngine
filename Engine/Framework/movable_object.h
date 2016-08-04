//
// Created by huxf on 2016/7/26.
//

#ifndef MAGICCUBE_MOVABLE_OBJECT_H
#define MAGICCUBE_MOVABLE_OBJECT_H

#include <string>
#include "node.h"

using namespace std;

namespace Magic
{

    class MovableObject
    {

    public:

        MovableObject();
        virtual ~MovableObject();

    protected:

        string name_;
        Node* parentNode_;
        bool visible_;

    };
}
#endif //MAGICCUBE_MOVABLE_OBJECT_H
