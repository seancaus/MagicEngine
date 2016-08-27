//
// Created by Ziv on 16/8/26.
//

#ifndef MAGIC_CUBE_H
#define MAGIC_CUBE_H


#include <GL/glew.h>

class Cube
{

public:

    Cube();
    virtual ~Cube();

    void preBind();
    void draw();

protected:

    GLuint _vao,_vbo,_ebo,_ubo,_instanceMbo,_instanceCbo;


};


#endif //MAGIC_CUBE_H
