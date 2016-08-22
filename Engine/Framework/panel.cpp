//
// Created by Ziv on 16/7/4.
//

#include "panel.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "transform.h"

using namespace std;

static const float WIDTH = 640;
static const float HEIGHT = 480;

Panel::Panel():
        shader_("E:/Workspace/code/MagicEngine/Engine/Shaders/commonVertex.glsl",
                "E:/Workspace/code/MagicEngine/Engine/Shaders/commonFragment.glsl")
{
}

Panel::~Panel() {
    cout << "~Panel()" << endl;
}

void Panel::draw()
{
    shader_.use();

    bind();

    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
    model = glm::translate(model, transform_.translation);
//    model = glm::translate(model, glm::vec3(-.5f * size_.x, -.5f * size_.y, 0.0f));
//    model = glm::scale(model, transform_.scale);
    model = glm::rotate(model,90.0f,transform_.rotation);

    view = glm::translate(view, glm::vec3(-320.0f, -240.0f, -450.0f));

    projection = glm::perspective(45.0f, WIDTH / HEIGHT, 0.1f, 1000.0f);

//    shader_.setMatrix4("model",model);
//    shader_.setMatrix4("view",view);
//    shader_.setMatrix4("projection",projection);
//    shader_.setVector3f("ourColor",color_.r,color_.g,color_.b);

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

    float z = transform_.translation.z;
    float vertices[] = {0,0,z,  size_.x,0,z,  0,size_.y,z,   size_.x,size_.y,z};
    int indices[] = {0,1,2,  1,2, 3};

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