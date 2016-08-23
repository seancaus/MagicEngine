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

    void move();
protected:

    Vector3 _direction;
    vector<glm::vec2> _points;

    GLuint _vao;
    GLuint _vbo;
    GLuint _instanceVbo;

    shared_ptr<GPUProgram> _program;
};


#endif //MAGIC_SNAKE_H
