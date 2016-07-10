//
// Created by Ziv on 16/7/4.
//

#ifndef MAGICCUBE_PANEL_H
#define MAGICCUBE_PANEL_H

#include <GL/glew.h>
#include "object.h"
#include "transform.h"
#include "shader.h"

class Panel : Object{

public:

    Panel();
    virtual ~Panel();

    void preBind();
    void bind();
    void draw();
    void unbind();

public:

    Color       _color;
    glm::vec3   _position;
    glm::vec2   _size;

    GLuint _vao;
    GLuint _vbo;
    GLuint _ebo;

    Shader _program;
};


#endif //MAGICCUBE_PANEL_H
