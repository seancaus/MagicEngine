//
// Created by huxf on 2016/8/22.
//

#include "snake.h"



Snake::Snake():
_direction(0,1,0)
,_vao(0)
,_vbo(0)
{
    _points.push_back(vector<glm::vec2>::value_type(0,0));
    _program = make_shared<GPUProgram>("../Assets/glsl/point.vert","../Assets/glsl/point.frag");
}

Snake::~Snake()
{
    destroy();
}

void Snake::destroy()
{
    if(_vbo)
    {
        glDeleteBuffers(1,&_vbo);
    }

    if(_vao)
    {
        glDeleteBuffers(1,&_vao);
    }
}

void Snake::preBind()
{
    float vertexs[] = {-0.05f,  0.05f,.0,1
            ,0.05f, -0.05f,0,1
            ,0.05f, -0.05f,0,1
    };

    glGenVertexArrays(1, &_vao);
    glGenBuffers(1,&_vbo);
    glGenBuffers(1,&_instanceVbo);

    glBindVertexArray(_vao);
    glBindBuffer(GL_VERTEX_ARRAY,_vbo);

    glBufferData(GL_VERTEX_ARRAY, sizeof(vertexs),vertexs, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,0,(GLvoid*)0);

    glBindBuffer(GL_VERTEX_ARRAY, _instanceVbo);
    glBufferData(GL_VERTEX_ARRAY, sizeof(glm::mat2) * _points.size(),&_points[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,0,(GLvoid*)0);

    glBindBuffer(GL_VERTEX_ARRAY, 0);
    glVertexAttribDivisor(1,1);
    glBindVertexArray(0);
}

void Snake::bind()
{
    glBindVertexArray(_vao);
}

void Snake::draw()
{
    _program->use();
    bind();

    glDrawArraysInstanced(GL_POINTS,0,1,1);
    glBindVertexArray(0);
}

void Snake::move()
{

}

void Snake::setForward(bool dir)
{
    _direction.x = 0;
    _direction.y = dir ? 1 : -1;
}

void Snake::setRight(bool dir)
{
    _direction.y = 0;
    _direction.x = dir ? 1 : -1;
}