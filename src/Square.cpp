//
// Created by Ziv on 16/6/18.
//

#include <GL/glew.h>
#include "Square.h"
//#include <>

static GLfloat vertices[] = {
        // Positions          // Colors           // Texture Coords
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
        1.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left
};

static GLuint indices[] = {  // Note that we start from 0!
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
};

Square::Square():
_program("/Users/huxf/Documents/Workspace/ClionProjects/MagicCube/ShaderSource/VertexSource.glsl","/Users/huxf/Documents/Workspace/ClionProjects/MagicCube/ShaderSource/FragmentSource.glsl")
{
    glGenVertexArrays(1,&_vertexArray);
    glGenBuffers(1,&_vertexBuffer);
    glGenBuffers(1,&_elementArrayBuffer);
}

Square::~Square()
{
    glDeleteVertexArrays(1,&_vertexArray);
    glDeleteBuffers(1,&_vertexBuffer);
    glDeleteBuffers(1,&_elementArrayBuffer);
}


void Square::preBind()
{
    glBindVertexArray(_vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER,_vertexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_elementArrayBuffer);

    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8 * sizeof(GLfloat),(GLvoid*)0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8 * sizeof(GLfloat),(GLvoid*)(3* sizeof(GLfloat)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),indices,GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    glBindVertexArray(0);
}

void Square::bind()
{
    glBindVertexArray(_vertexArray);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_elementArrayBuffer);
}


void Square::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    glBindVertexArray(0);
}

void Square::drew()
{
    _program.use();

    bind();

//    int width = 640;
//    int height = 480;
//    int zorder = 1000;
//
//    float newx = x/width;
//    float newy = x/height;
//    float newz = x/z;
//
//    float newXend = _long / width + newx;
//    float newYend = _width / height + newY;
//    float newXend =  / width + newz;




    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    unbind();
}


