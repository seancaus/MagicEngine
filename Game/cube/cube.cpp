//
// Created by Ziv on 16/8/26.
//

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "cube.h"


Cube::Cube(shared_ptr<CubeCamera> camera)
{
    _camera = camera;
    _program = make_shared<GPUProgram>("../Assets/glsl/cube.vert","../Assets/glsl/cube.frag");

    glm::mat4 originalMat4[6];
    glm::mat4 rotateMat4[6];
    glm::vec3 directions[6];

    glm::mat4 im;
    glm::mat4 ocm;
    ocm = glm::translate(ocm, glm::vec3(-15, -15, .0));

    //前蓝
    glm::mat4 m;
    m = glm::translate(ocm, glm::vec3(.0, .0, 47.0));
    originalMat4[0] = m;
    rotateMat4[0] = im;
    directions[0] = glm::vec3(1,0,0);
    directions[1] = glm::vec3(0,1,0);

    //后绿
    m = glm::translate(ocm, glm::vec3(.0, .0, -47.0));
    originalMat4[1] = m;
    rotateMat4[1] = im;

    //上白------------------------------------------------------------
    m = glm::translate(ocm, glm::vec3(.0, 62, 15));
    originalMat4[2] = m;
    m = glm::rotate(im,glm::radians(-90.0f),glm::vec3(1,0,0));
    rotateMat4[2] = m;
    directions[2] = glm::vec3(1,0,0);
    directions[3] = glm::vec3(0,0,1);

    //下黄
    m = glm::translate(ocm, glm::vec3(.0, -32, 15.0));
    originalMat4[3] = m;
    m = glm::rotate(im,glm::radians(-90.0f),glm::vec3(1,0,0));
    rotateMat4[3] = m;

    //左红------------------------------------------------------------
    m = glm::translate(ocm, glm::vec3(-32.0, .0, -15.0));
    originalMat4[4] = m;
    m = glm::rotate(im,glm::radians(-90.0f),glm::vec3(0,1,0));
    rotateMat4[4] = m;
    directions[4] = glm::vec3(0,0,1);
    directions[5] = glm::vec3(0,1,0);

//    //右橙
    m = ocm;
    m = glm::translate(ocm, glm::vec3(62.0, .0, 15.0));
    originalMat4[5] = m;
    m = glm::rotate(im,glm::radians(90.0f),glm::vec3(0,.5,0));
    rotateMat4[5] = m;

    for (int j = 0; j < 6; ++j) {
        int di = (1==(j % 2))?j-1:j;
        auto om = originalMat4[j];
        auto rm = rotateMat4[j];
        for (int i = 0; i < 9; ++i)
        {
            float r = (i / 3 - 1) * 32;
            float c = (i % 3 - 1) * 32;

            auto tm1 = directions[di] * r;
            auto tm2 = directions[di+1] * c;

            glm::mat4 m = glm::translate(om, tm1 + tm2);
            m = m * rm;
            _models.push_back(m);
        }
    }

    _projection = glm::perspective(45.0f, 500.0f / 500.0f, .1f, 10000.f);
}

Cube::~Cube()
{
}

void Cube::preBind()
{
    float verties[] = {
            .0,.0,.0
            ,30,30,.0
            ,0,30,.0
            ,30,0,.0
    };

    float colors[] = {
            .0,.0,1.0//前蓝
            ,.0,1.0,0//后绿

            ,1.0,1.0,1.0//上白
            ,1.0,1.0,0  //下黄

            ,1.0,.0,.0//左红
            ,1.0,.5,.0//右橙
    };

    int indices[] = {0,1,2,0,3,1};

    glGenVertexArrays(1,&_vao);
    glBindVertexArray(_vao);

    //pos
    glGenBuffers(1,&_vbo);
    glBindBuffer(GL_ARRAY_BUFFER,_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verties),verties,GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3* sizeof(float), (GLvoid*)0);

    //color
    glGenBuffers(1,&_color_vbo);
    glBindBuffer(GL_ARRAY_BUFFER,_color_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors),colors,GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,3* sizeof(float),(GLvoid*)0);
    glVertexAttribDivisor(1,9);

    //model
    int mat4Size = sizeof(glm::mat4);
    int vec4Size = sizeof(glm::vec4);
    glGenBuffers(1,&_model_vbo);
    glBindBuffer(GL_ARRAY_BUFFER,_model_vbo);
    glBufferData(GL_ARRAY_BUFFER, mat4Size * _models.size(), _models.data() ,GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(2);//位置要对准
    glVertexAttribPointer(2,4,GL_FLOAT,GL_FALSE,mat4Size,(GLvoid*)0);
    glVertexAttribDivisor(2,1);
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3,4,GL_FLOAT,GL_FALSE,mat4Size,(GLvoid*)(vec4Size));
    glVertexAttribDivisor(3,1);
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4,4,GL_FLOAT,GL_FALSE,mat4Size,(GLvoid*)(vec4Size*2));
    glVertexAttribDivisor(4,1);
    glEnableVertexAttribArray(5);
    glVertexAttribPointer(5,4,GL_FLOAT,GL_FALSE,mat4Size,(GLvoid*)(vec4Size*3));
    glVertexAttribDivisor(5,1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //Matrices
    glGenBuffers(1,&_ubo);
    glBindBuffer(GL_UNIFORM_BUFFER,_ubo);
    glBufferData(GL_UNIFORM_BUFFER,mat4Size *2,NULL,GL_STREAM_READ);
    glBufferSubData(GL_UNIFORM_BUFFER,0,mat4Size,glm::value_ptr(_camera->getViewMatrix()));
    glBufferSubData(GL_UNIFORM_BUFFER,mat4Size,mat4Size,glm::value_ptr(_projection));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    _program->bindUniformBuffer("Matrices",_ubo);
    glBindVertexArray(0);

    glGenBuffers(1,&_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),indices,GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}

void Cube::updateCamera()
{
    int mat4Size = sizeof(glm::mat4);
    glBindBuffer(GL_UNIFORM_BUFFER,_ubo);
    glBufferSubData(GL_UNIFORM_BUFFER,0,mat4Size,glm::value_ptr(_camera->getViewMatrix()));
    glBindBuffer(GL_UNIFORM_BUFFER,_ubo);
}

void Cube::draw()
{
    _program->use();
    glEnable(GL_DEPTH_TEST);
    glBindVertexArray(_vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_ebo);//不要绑定错

    glDrawElementsInstanced(GL_TRIANGLES,6,GL_UNSIGNED_INT, nullptr,_models.size());

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    glBindVertexArray(0);
}