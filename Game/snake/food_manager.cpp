//
// Created by huxf on 2016/8/26.
//

#include "food_manager.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

FoodManager::FoodManager()
{
    _program = make_shared<GPUProgram>("../Assets/glsl/food.vert","../Assets/glsl/food.frag");

    string images[4];
    images[(int)Food_Apple] = "apple.png";
    images[(int)Food_Kiwi] ="Kiwi.png";
    images[(int)Food_Peach] ="Peach.png";
    images[(int)Food_Tomoto] ="Tomoto.png";
    for (auto img:images)
    {
        auto tex = make_shared<Texture>(_program);
        tex->loadTexture("../Assets/Textures/snake/" + img);
        _textures.push_back(tex);
    }

    createNewFood(Food_Apple,300,100);
    createNewFood(Food_Tomoto,200,200);
    createNewFood(Food_Peach,100,200);
    createNewFood(Food_Kiwi,200,400);
}

FoodManager::~FoodManager()
{
}

void FoodManager::destroy()
{
    if (_vao)
    {
        glDeleteVertexArrays(1,&_vao);
        _vao = 0;
    }
    if (_vbo)
    {
        glDeleteBuffers(1,&_vbo);
        _vbo = 0;
    }
    if (_ebo)
    {
        glDeleteBuffers(1,&_vbo);
        _vbo = 0;
    }
    if (_ibo)
    {
        glDeleteBuffers(1,&_ibo);
        _ibo = 0;
    }
    if (_ubo)
    {
        glDeleteBuffers(1,&_ubo);
        _ubo = 0;
    }
}

void FoodManager::createNewFood(FoodType type, int x, int y)
{
    cout <<"FoodType" << (int)type <<endl;

    glm::mat4 m;
    m = glm::translate(m,glm::vec3(x,y,1));
    _foodsPos.push_back(m);
    _foodsType.push_back(1.0f * (int)type);
}

void FoodManager::preBind()
{
    destroy();

    float verties[] = {
            0,0
            ,30,30
            ,0,30
            ,30,0

            ,0,0
            ,1,1
            ,0,1
            ,1,0
    };

    int indices[] = {
            0,1,2,0,3,1
    };

    int mat4Size = sizeof(glm::mat4);
    int vec4Size = sizeof(glm::vec4);

    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);

    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verties), verties, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,2 * sizeof(float),(GLvoid*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,2 * sizeof(float),(GLvoid*)(8 * sizeof(float)));

    //------------------------------------------------------------------------------------------
    glGenBuffers(1, &_ibo);
    glBindBuffer(GL_ARRAY_BUFFER, _ibo);
    glBufferData(GL_ARRAY_BUFFER, mat4Size * _foodsPos.size(), _foodsPos.data() ,GL_STREAM_READ);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2,4,GL_FLOAT,GL_FALSE,mat4Size,(GLvoid*)0);
    glVertexAttribDivisor(2,1);

    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3,4,GL_FLOAT,GL_FALSE,mat4Size,(GLvoid*)(vec4Size));
    glVertexAttribDivisor(3,1);

    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4,4,GL_FLOAT,GL_FALSE,mat4Size,(GLvoid*)(2*vec4Size));
    glVertexAttribDivisor(4,1);

    glEnableVertexAttribArray(5);
    glVertexAttribPointer(5,4,GL_FLOAT,GL_FALSE,mat4Size,(GLvoid*)(3*vec4Size));
    glVertexAttribDivisor(5,1);

    //顶点属性 只能是float vec2...4 mat2...4
    glGenBuffers(1,&_typeBo);
    glBindBuffer(GL_ARRAY_BUFFER,_typeBo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*_foodsType.size(),_foodsType.data(),GL_STREAM_READ);
    glEnableVertexAttribArray(6);
    glVertexAttribPointer(6,1,GL_FLOAT,GL_FALSE, sizeof(float),(GLvoid*)0);
    glVertexAttribDivisor(6,1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //------------------------------------------------------------------------------------------
    glm::mat4 projection;
    glm::mat4 view;
    projection = glm::ortho(.0,500.0,.0,500.0,.1,100.0);
    view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
                       glm::vec3(0.0f, 0.0f, 0.0f),
                       glm::vec3(0.0f, 1.0f, 0.0f));

    glGenBuffers(1,&_ubo);
    glBindBuffer(GL_UNIFORM_BUFFER,_ubo);
    glBufferData(GL_UNIFORM_BUFFER, mat4Size * 2,NULL,GL_STREAM_READ);
    glBufferSubData(GL_UNIFORM_BUFFER,0,mat4Size,glm::value_ptr(view));
    glBufferSubData(GL_UNIFORM_BUFFER,mat4Size,mat4Size,glm::value_ptr(projection));
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    _program->bindUniformBuffer("Matrices",_ubo);
    glBindVertexArray(0);

    glGenBuffers(1, &_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),indices,GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}

void FoodManager::draw()
{
    _program->use();
    string sampler[] = {"samTex1","samTex2","samTex3","samTex4"};
    for(int i = 0;i <_textures.size();++i)
    {
        auto tex = _textures[i];
        tex->bindSampler2D(sampler[i],i);
    }

    glBindVertexArray(_vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);

    glDrawElementsInstanced(GL_TRIANGLES,6,GL_UNSIGNED_INT,nullptr,_foodsPos.size());

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}