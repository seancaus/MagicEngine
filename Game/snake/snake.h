//
// Created by huxf on 2016/8/22.
//

#ifndef MAGIC_SNAKE_H
#define MAGIC_SNAKE_H

#include <memory>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "../../Engine/Framework/gpu_program.h"
#include "../../Engine/Framework/vector3.h"

using namespace std;
using namespace Magic;

typedef vector<glm::mat4> PointList;

class Snake
{

public:
    Snake();
    virtual ~Snake();
    void destroy();

    void preBind();
    void bind();
    void draw();

    void setForward(bool dir);
    void setRight(bool dir);
    void grow();
    void move();
protected:

    Vector3 _direction;
    PointList _points;

    GLuint _vao;
    GLuint _vbo;
    GLuint _instanceVbo;
    GLuint _uboMatrices;

    shared_ptr<GPUProgram> _program;

    int _pointSize;
};


#endif //MAGIC_SNAKE_H
