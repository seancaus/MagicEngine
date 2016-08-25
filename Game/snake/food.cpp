//
// Created by Ziv on 16/8/25.
//

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "food.h"

namespace magic {


    Food::Food(FoodType type):
    _ebo(0)
    ,_ibo(0)
    ,_type(type)
    ,_vao(0)
    ,_vbo(0)
    {
        _program = make_shared<GPUProgram>("../Assets/glsl/food.vert","../Assets/glsl/food.frag");
    }

    Food::~Food()
    {
    }

    void Food::destroy()
    {
//        if ()
//        {
//
//        }
    }

    void Food::preBind()
    {
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

        glGenVertexArrays(1,&_vao);
        glGenBuffers(1,&_vbo);
        glGenBuffers(1,&_ibo);
        glGenBuffers(1,&_ubo);

        glBindVertexArray(_vao);
        glBindBuffer(GL_ARRAY_BUFFER,_vbo);

        glBufferData(GL_ARRAY_BUFFER, sizeof(verties),verties,GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0,2,GL_FLAT,GL_FALSE,2* sizeof(float),(GLvoid*)0);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1,2,GL_FLAT,GL_FALSE,2* sizeof(float),(GLvoid*)(8* sizeof(float)));

        glBindBuffer(GL_ARRAY_BUFFER,_ibo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::mat4),nullptr,GL_STREAM_DRAW);
        int vec4Size = sizeof(glm::vec4);
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2,4,GL_FLAT,GL_FALSE, 4 * vec4Size,(GLvoid*)0);
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3,4,GL_FLAT,GL_FALSE, 4 * vec4Size,(GLvoid*)vec4Size);
        glEnableVertexAttribArray(4);
        glVertexAttribPointer(4,4,GL_FLAT,GL_FALSE, 4 * vec4Size,(GLvoid*)(2*vec4Size));
        glEnableVertexAttribArray(5);
        glVertexAttribPointer(5,4,GL_FLAT,GL_FALSE, 4 * vec4Size,(GLvoid*)(3*vec4Size));
        glVertexAttribDivisor(2,1);
        glVertexAttribDivisor(3,1);
        glVertexAttribDivisor(4,1);
        glVertexAttribDivisor(5,1);
        glBindBuffer(GL_ARRAY_BUFFER,0);

        glBindBuffer(GL_UNIFORM_BUFFER,_ubo);
        int mat4Size = sizeof(glm::mat4);
        glBufferData(GL_UNIFORM_BUFFER,2* mat4Size,NULL,GL_STATIC_DRAW);
        glBufferSubData(GL_UNIFORM_BUFFER,0, mat4Size, nullptr);
        glBufferSubData(GL_UNIFORM_BUFFER,mat4Size, mat4Size, nullptr);
        glBindBuffer(GL_UNIFORM_BUFFER,0);
        _program->bindUniformBuffer("Matrices",_ubo);

        glBindVertexArray(0);

        glGenBuffers(1,&_ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),indices,GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    }

    void Food::draw()
    {
        glBindVertexArray(_vao);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_ebo);

        glDrawElementsInstanced(GL_TRIANGLES,6,GL_UNSIGNED_INT,nullptr,10);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
        glBindVertexArray(0);
    }

}