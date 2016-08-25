//
// Created by huxf on 2016/8/19.
//

#ifndef MAGIC_FRAGMENTSHADER_H
#define MAGIC_FRAGMENTSHADER_H

#include "shader.h"

namespace magic {
    class FragmentShader : public Shader {

    public:

        FragmentShader(const string &source);

    protected:
        virtual GLuint createShader() override;


    };
}

#endif //MAGIC_FRAGMENTSHADER_H
