//
// Created by Ziv on 16/8/26.
//

#ifndef MAGIC_SNAKE_UTILS_H
#define MAGIC_SNAKE_UTILS_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

class SnakeUtils
{
public:
    static void getRowAndCell(const glm::mat4 mat,int& row,int& col,glm::vec2 offset=glm::vec2(0,0));
    static glm::vec2 genMat4(const int& row,const int& col,glm::vec2 offset=glm::vec2(0,0));

    static int rand(int min,int max);
};


#endif //MAGIC_SNAKE_UTILS_H
