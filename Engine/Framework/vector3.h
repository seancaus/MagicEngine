//
// Created by huxf on 2016/7/26.
//

#ifndef MAGICCUBE_VECTOR3_H
#define MAGICCUBE_VECTOR3_H

namespace Magic {

    class Vector3 {

    public:

        float x, y, z;

        inline Vector3():
                x(.0f),y(.0f),z(.0f)
        {

        }

        inline Vector3(const float x, const float y, const float z):
                x(x),y(y),z(z)
        {
        }

        static const Vector3 ZERO;

    };
}


#endif //MAGICCUBE_VECTOR3_H
