//
// Created by huxf on 2016/8/19.
//

#ifndef MAGIC_SHADER_H
#define MAGIC_SHADER_H

#include <GL/glew.h>
#include <string>

using namespace std;

namespace magic {

    class Shader {

    public:
        Shader(const string &source);

        virtual ~Shader();

        GLuint getShaderID() const;

        void setSource(const string &source);

    protected:

        void deleteShader();

        virtual GLuint createShader() = 0;

        GLuint _shaderID;
        string _source;
    };
}

#endif //MAGIC_SHADER_H
