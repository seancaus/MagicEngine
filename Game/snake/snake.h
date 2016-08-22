//
// Created by huxf on 2016/8/22.
//

#ifndef MAGIC_SNAKE_H
#define MAGIC_SNAKE_H

#include <GL/glew.h>
#include "../../Engine/Framework/vector3.h"

using namespace Magic;

class Snake
{

public:
    Snake();
    virtual ~Snake();

    void draw();

    void setForward(bool dir);
    void setRight(bool dir);
protected:

    Vector3 _direction;


};


#endif //MAGIC_SNAKE_H
