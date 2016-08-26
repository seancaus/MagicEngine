//
// Created by huxf on 2016/8/26.
//

#ifndef MAGIC_FOOD_MANAGER_H
#define MAGIC_FOOD_MANAGER_H

#include <memory>
#include <vector>
#include <GL/glew.h>
#include "../../Engine/Framework/gpu_program.h"
#include "../../Engine/Framework/texture.h"
#include "food.h"

using namespace std;
using namespace magic;

//class Food;

typedef vector<shared_ptr<Food>> FoodPool;

class FoodManager
{

public:

    FoodManager();
    virtual ~FoodManager();
    void destroy();

    void preBind();
    void draw();
    void createNewFood(FoodType,int x,int y);

protected:
    GLuint _vao,_vbo,_ebo,_ubo,_ibo,_typeBo;

    vector<glm::mat4>           _foodsPos;
    vector<float>               _foodsType;
//    FoodPool                    _foods;
    shared_ptr<GPUProgram>      _program;
    vector<shared_ptr<Texture>> _textures;
};


#endif //MAGIC_FOOD_POOL_H
