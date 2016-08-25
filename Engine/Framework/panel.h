//
// Created by Ziv on 16/7/4.
//

#ifndef MAGICCUBE_PANEL_H
#define MAGICCUBE_PANEL_H

#include <GL/glew.h>

#include "object.h"
#include "transform.h"
#include "gpu_program.h"
#include "movable_object.h"
#include "renderable.h"

using  namespace magic;

class Panel : public MovableObject, public Renderable
{

public:

    Panel();
    virtual ~Panel();

    void preBind();
    void bind();
    void draw();
    void unbind();

public:

    glm::vec4   color_;
    Transform   transform_;
    glm::vec3   size_;

    GLuint _vao;
    GLuint _vbo;
    GLuint _ebo;

    GPUProgram shader_;
};


#endif //MAGICCUBE_PANEL_H
