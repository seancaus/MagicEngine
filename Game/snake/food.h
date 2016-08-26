//
// Created by Ziv on 16/8/25.
//

#ifndef MAGIC_FOOD_H
#define MAGIC_FOOD_H

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "../../Engine/Framework/texture.h"
#include "../../Engine/Framework/gpu_program.h"
#include "../../Engine/Framework/vector3.h"

namespace magic {

    enum FoodType
    {
        Food_Apple = 0,
        Food_Kiwi = 1,      //猕猴桃
        Food_Peach = 2,     //桃子
        Food_Tomoto = 3    //西红柿
    };

    class Food
    {

    public:

        Food(FoodType ft = Food_Apple);
        virtual ~Food();


        FoodType getType() const {
            return _type;
        }

        void setType(FoodType type) {
            this->_type = type;
        }


        const Vector3 &getPosition() const {
            return _position;
        }

        void setPosition(const Vector3 &position) {
            this->_position = position;
        }

    protected:

        FoodType    _type;
        Vector3     _position;

    };
}
#endif //MAGIC_FOOD_H
