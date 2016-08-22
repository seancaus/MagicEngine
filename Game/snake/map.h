//
// Created by huxf on 2016/8/22.
//

#ifndef MAGIC_MAP_H
#define MAGIC_MAP_H

#include <vector>
#include "../../Engine/Framework/vector3.h"

using namespace std;
using namespace Magic;

class Map
{

public:

    Map();
    virtual ~Map();

protected:

    vector<Vector3> _obstacle;


};


#endif //MAGIC_MAP_H
