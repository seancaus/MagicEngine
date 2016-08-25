//
// Created by Ziv on 16/8/25.
//

#ifndef MAGIC_FOOD_H
#define MAGIC_FOOD_H

#include <GL/glew.h>
#include "../../Engine/Framework/gpu_program.h"

namespace magic {

    enum FoodType
    {
        Food_Apple,
        Food_Kiwi,      //猕猴桃
        Food_Peach,     //桃子
        Food_Tomoto,    //西红柿
        Food_Strawberry //草莓
    };

    class Food
    {

    public:

        Food(FoodType);
        virtual ~Food();
        void destroy();

        void preBind();
        void draw();

    protected:

        FoodType _type;
        GLuint _vao,_vbo,_ebo,_ibo,_ubo;

        shared_ptr<GPUProgram> _program;

    };
}
#endif //MAGIC_FOOD_H
