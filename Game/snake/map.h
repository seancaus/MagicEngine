//
// Created by huxf on 2016/8/22.
//

#ifndef MAGIC_MAP_H
#define MAGIC_MAP_H

#include <memory>
#include <vector>
#include <GL/glew.h>
#include "../../Engine/Framework/gpu_program.h"
#include "../../Engine/Framework/vector3.h"
#include "food.h"

using namespace std;

namespace magic
{

    typedef vector<shared_ptr<Food>> FoodList;

    class Map {

    public:
        Map();
        virtual ~Map();

        void destroy();
        void preBind();
        void draw();
        void createFood();
        int rand(int min,int max);

    protected:

        GLuint _vao, _vbo, _ebo, _tex, _pbo;

        int _width;
        int _height;

        FoodList _foods;
        shared_ptr<GPUProgram> _program;
    };
}
#endif //MAGIC_MAP_H
