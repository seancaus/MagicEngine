//
// Created by huxf on 2016/8/19.
//

#ifndef MAGIC_VERTEXSHADER_H
#define MAGIC_VERTEXSHADER_H

#include "shader.h"

using namespace std;

namespace Magic
{

    class VertexShader :public Shader{

    public:

        VertexShader(string source);
        virtual ~VertexShader();

    protected:

        virtual GLuint createShader() override;


    };

}
#endif //MAGIC_VERTEXSHADER_H
