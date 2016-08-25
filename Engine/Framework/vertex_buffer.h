//
// Created by Ziv on 16/8/9.
//

#ifndef MAGIC_VERTEX_BUFFER_H
#define MAGIC_VERTEX_BUFFER_H

#include <GL/glew.h>

namespace magic
{

    class VertexBuffer
    {
    public:
        VertexBuffer();
        ~ VertexBuffer();

    protected:

        GLuint bufferId_;

    };
}

#endif //MAGIC_VERTEX_BUFFER_H
