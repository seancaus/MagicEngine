//
// Created by Ziv on 16/6/18.
//

#ifndef MAGICCUBE_SQUARE_H
#define MAGICCUBE_SQUARE_H

#include <vector>
#include "../Engine/Framework/shader.h"

using namespace std;

class Square {

public:
    Square();
    virtual ~Square();

    void preBind();
    void bind();
    void unbind();
    void drew();


    float get_x() const {
        return _x;
    }

    void set_x(float _x) {
        Square::_x = _x;
    }

    float get_y() const {
        return _y;
    }

    void set_y(float _y) {
        Square::_y = _y;
    }

    float get_z() const {
        return _z;
    }

    void set_z(float _z) {
        Square::_z = _z;
    }


    float get_width() const {
        return _width;
    }

    void set_width(float _width) {
        Square::_width = _width;
    }

    float get_heigth() const {
        return _heigth;
    }

    void set_heigth(float _heigth) {
        Square::_heigth = _heigth;
    }


    float get_long() const {
        return _long;
    }

    void set_long(float _long) {
        Square::_long = _long;
    }

protected:
    GLuint _vertexArray;
    GLuint _elementArrayBuffer;
    GLuint _vertexBuffer;

    float _x;
    float _y;
    float _z;
    float _width;
    float _heigth;
    float _long;

    Shader _program;
};


#endif //MAGICCUBE_SQUARE_H
