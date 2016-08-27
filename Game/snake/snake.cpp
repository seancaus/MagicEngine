//
// Created by huxf on 2016/8/22.
//

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "snake.h"
#include <GLFW/glfw3.h>

extern GLfloat deltaTime;

Snake::Snake():
_direction(0,1,0)
,_vao(0)
,_vbo(0)
,_pointSize(30)
,_lastMoveTime(0)
{
    glm::mat4 m;
    int center = 265/31*31 +15;
    m = glm::translate(m,glm::vec3(center,center,.0));
    _points.push_back(m);

    m = glm::translate(m,glm::vec3(0,-31,.0));
    _points.push_back(m);
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

    if(_instanceVbo)
    {
        glDeleteBuffers(1,&_instanceVbo);
    }
}

void Snake::preBind()
{
    destroy();

    glPointSize(_pointSize);

    float vertexs[] = { .0f ,.0f };

    glm::mat4 projection;
    glm::mat4 view;
    projection = glm::ortho(.0,500.0,.0,500.0,.1,100.0);
    view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
                       glm::vec3(0.0f, 0.0f, 0.0f),
                       glm::vec3(0.0f, 1.0f, 0.0f));

    glGenVertexArrays(1, &_vao);
    glGenBuffers(1,&_vbo);
    glGenBuffers(1,&_instanceVbo);
    glGenBuffers(1,&_uboMatrices);

    glBindVertexArray(_vao);

    glBindBuffer(GL_ARRAY_BUFFER,_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexs),vertexs, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (GLvoid*)0);

    // 实例化数组
    glBindBuffer(GL_ARRAY_BUFFER, _instanceVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::mat4) * _points.size(), _points.data(), GL_STATIC_DRAW);
    auto vec4Size = sizeof(glm::vec4);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1 ,4 ,GL_FLOAT ,GL_FALSE ,4 * vec4Size ,(GLvoid*)0);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2 ,4 ,GL_FLOAT ,GL_FALSE ,4 * vec4Size ,(GLvoid*)vec4Size);
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3 ,4 ,GL_FLOAT ,GL_FALSE ,4 * vec4Size ,(GLvoid*)(2 * vec4Size));
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4 ,4 ,GL_FLOAT ,GL_FALSE ,4 * vec4Size ,(GLvoid*)(3 * vec4Size));
    glVertexAttribDivisor(1,1);
    glVertexAttribDivisor(2,1);
    glVertexAttribDivisor(3,1);
    glVertexAttribDivisor(4,1);

    // Uniform Buffer Object
    glBindBuffer(GL_UNIFORM_BUFFER, _uboMatrices);
    glBufferData(GL_UNIFORM_BUFFER, 2*sizeof(glm::mat4), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(view));
    glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(projection));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    _program->bindUniformBuffer("Matrices",_uboMatrices);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
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
    glDrawArraysInstanced(GL_POINTS,0,1,_points.size());
    glBindVertexArray(0);
}

void Snake::move()
{
    auto time = glfwGetTime();
    if(time - _lastMoveTime <= 1.0f) return;

    glm::mat4 next;
    glm::vec3 dir(_direction.x,_direction.y,0);
    dir *= 31.0f;
    auto head = _points.front();
    next = glm::translate(head,dir);

    _points.pop_back();
    _points.insert(_points.begin(),next);


    glBindBuffer(GL_ARRAY_BUFFER, _instanceVbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0 ,sizeof(glm::mat4) * _points.size(),_points.data());
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    _lastMoveTime = time;

//    cout << "snake Pos:" << getPosition() << endl;
}

void Snake::grow()
{
    glm::vec3 dir(_direction.x,_direction.y,_direction.z);
    dir *= 31;
    glm::mat4 m = glm::translate(_points[0] , dir);

    _points.insert(_points.begin(),m);

    glBindBuffer(GL_ARRAY_BUFFER, _instanceVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::mat4) * _points.size(), _points.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

int Snake::getLength()
{
    return _points.size();
}

glm::mat4 Snake::getPosition() {
    return _points[0];
}

void Snake::setForward(bool dir)
{
    if(_direction.y == 0)
    {
        _direction.x = 0;
        _direction.y = dir ? 1 : -1;
    }
}

void Snake::setRight(bool dir)
{
    if(_direction.x == 0) {
        _direction.y = 0;
        _direction.x = dir ? 1 : -1;
    }
}