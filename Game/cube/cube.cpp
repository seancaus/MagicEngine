//
// Created by Ziv on 16/8/26.
//

#include "cube.h"


Cube::Cube() {

}

Cube::~Cube() {

}


void Cube::preBind()
{
    float verties[] = {
            0,0,1
            ,30,30,1
            ,0,30,1
            ,30,0,1
    };

    int indies[] = {0,1,2,0,3,1};

    glGenVertexArrays(1,&_vao);
    glBindVertexArray(_vao);

    glGenBuffers(1,&_vbo);
    glBindBuffer(GL_ARRAY_BUFFER,_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verties),verties,GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(0,2);

}

void Cube::draw()
{

}