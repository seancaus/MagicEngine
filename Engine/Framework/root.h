//
// Created by huxf on 2016/7/21.
//

#ifndef MAGICCUBE_ROOT_H
#define MAGICCUBE_ROOT_H

#include "singleton.h"

class Root :public  Singleton<Root>
{

public:

    Root();
    virtual ~Root();

};


#endif //MAGICCUBE_ROOT_H
