//
// Created by huxf on 2016/8/22.
//

#include "map.h"


Map::Map():
_vao(0),
_vbo(0)
{
    _obstacle.push_back(Vector3(1,2,3));
}

Map::~Map()
{
    this->destroy();
}

void Map::destroy()
{
    if(!_vao)
    {
        glDeleteVertexArrays(1,&_vao);
        _vao = 0;
    }

    if(!_vao)
    {
        glDeleteBuffers(1,&_vbo);
        _vbo = 0;
    }
}

void Map::preBind()
{
    destroy();

    glGenVertexArrays(1,&_vao);
    glGenBuffers(1,&_vbo);

    glBindVertexArray(_vao);
    glBindBuffer(GL_ARRAY_BUFFER,_vbo);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,_obstacle.size() * sizeof(Vector3),GL_FLOAT,GL_FALSE,sizeof(Vector3),(GLvoid*)0);

}

void Map::draw()
{

}