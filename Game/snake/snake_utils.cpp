//
// Created by Ziv on 16/8/26.
//

#include <glm/detail/type_mat.hpp>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "snake_utils.h"

void SnakeUtils::getRowAndCell(const glm::mat4 mat, int &row, int &col,glm::vec2 offset)
{
    auto pos = mat[3];
    col = (pos.x + offset.x) / 31;
    row = (pos.y + offset.y) / 31;
}

glm::vec2 SnakeUtils::genMat4(const int &row, const int& col,glm::vec2 offset)
{
    glm::vec2 v(col * 31 + offset.x, row * 31 + offset.y);
    return v;
}

int SnakeUtils::rand(int min, int max)
{
    return (::rand() % (max - min + 1))+ min;
}

