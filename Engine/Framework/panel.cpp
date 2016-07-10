//
// Created by Ziv on 16/7/4.
//

#include "panel.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

using namespace std;

static const float WIDTH = 640;
static const float HEIGHT = 480;

Panel::Panel():
        _program("/Users/huxf/Documents/Workspace/ClionProjects/MagicCube/Engine/Shaders/commonVertex.glsl",
                "/Users/huxf/Documents/Workspace/ClionProjects/MagicCube/Engine/Shaders/commonFragment.glsl")
{

}

Panel::~Panel() {

}

void Panel::draw()
{
    _program.use();

    bind();

    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
    glm::vec2 pos = {10,10};
//    model = glm::translate(model, glm::vec3(pos, 0.0f));
//    model = glm::translate(model, glm::vec3(0.5f * _size.x, 0.5f * _size.y, 0.0f));
//    model = glm::translate(model, glm::vec3(-0.5f * _size.x, -0.5f * _size.y, 0.0f));
    model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    projection = glm::perspective(45.0f, WIDTH / HEIGHT, 0.1f, 100.0f);

    _program.setMatrix4("model",model);
    _program.setMatrix4("view",view);
    _program.setMatrix4("projection",projection);
    _program.setVector3f("ourColor",_color.r,_color.g,_color.b);


    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
    unbind();
}

void Panel::preBind()
{
    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);

    glBindVertexArray(_vao);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_ebo);

    float vertices[] = {0,1,0,  0,0,0, 1,0,0,  1,1,0};
    int indices[] = {0,1,2,  0,2, 3};

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),indices,GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    glBindVertexArray(0);
}

void Panel::bind()
{
    glBindVertexArray(_vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
}

void Panel::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}