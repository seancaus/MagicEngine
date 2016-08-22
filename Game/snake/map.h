//
// Created by huxf on 2016/8/22.
//

#ifndef MAGIC_MAP_H
#define MAGIC_MAP_H

#include <vector>
#include <GL/glew.h>
#include "../../Engine/Framework/vector3.h"

using namespace std;
using namespace Magic;

class Map
{

public:

    Map();
    virtual ~Map();

    void destroy();
    void preBind();
    void draw();

protected:

    vector<Vector3> _obstacle;

    GLuint _vao,_vbo;


};


#endif //MAGIC_MAP_H
