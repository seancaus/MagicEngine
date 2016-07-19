//
// Created by Ziv on 16/6/20.
//

#ifndef MAGICCUBE_TRANSFORM_H
#define MAGICCUBE_TRANSFORM_H

#include "glm/glm.hpp"

typedef struct
{
    glm::vec3 rotation;
    glm::vec3 translation;
    glm::vec3 scale;
}Transform;

#endif //MAGICCUBE_TRANSFORM_H
