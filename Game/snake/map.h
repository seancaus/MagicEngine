//
// Created by huxf on 2016/8/22.
//

#ifndef MAGIC_MAP_H
#define MAGIC_MAP_H

#include <memory>
#include <vector>
#include <GL/glew.h>
#include <bits/shared_ptr.h>
#include "../../Engine/Framework/gpu_program.h"
#include "../../Engine/Framework/vector3.h"

using namespace std;
using namespace magic;

class Map
{

public:

    Map();
    virtual ~Map();

    void destroy();
    void preBind();
    void draw();

protected:

    GLuint _vao,_vbo,_ebo,_tex,_pbo;

    int width;
    int height;

    shared_ptr<GPUProgram> _program;
};


#endif //MAGIC_MAP_H
