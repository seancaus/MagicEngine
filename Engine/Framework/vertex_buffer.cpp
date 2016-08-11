//
// Created by Ziv on 16/8/9.
//

#include "vertex_buffer.h"

namespace Magic
{

    VertexBuffer::VertexBuffer()
    {
//        glGenVertexArrays(1, &_vao);
//        glBindVertexArray(_vao);
//        glBindVertexArray(0);

//        glGenBuffers(1, &_ebo);
//        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_ebo);
//        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),indices,GL_STATIC_DRAW);
//        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

        glGenBuffers(1, &bufferId_);
        glBindBuffer(GL_ARRAY_BUFFER, bufferId_);

//        float z = transform_.translation.z;
//        float vertices[] = {0,0,z,  size_.x,0,z,  0,size_.y,z,   size_.x,size_.y,z};
//        int indices[] = {0,1,2,  1,2, 3};

//        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER,0);
    }
    //-----------------------------------------------------------------------
    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &bufferId_);
    }
    //-----------------------------------------------------------------------
}