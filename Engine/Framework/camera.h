//
// Created by huxf on 2016/7/19.
//

#ifndef MAGICCUBE_CAMERA_H
#define MAGICCUBE_CAMERA_H

#include "object.h"

class Camera : public Object
{
public:

    Camera();
    virtual ~Camera();


    void LookAt();

protected:



private:

};


#endif //MAGICCUBE_CAMERA_H
