//
// Created by huxf on 2016/8/19.
//

#include <GL/glew.h>
#include "Shader.h"


Shader::Shader(const string& source):
_shaderID(0)
,_source(source)
{
}

Shader::~Shader()
{
    deleteShader();
}


void Shader::deleteShader()
{
    if(_shaderID)
    {
        glDeleteShader(_shaderID);
        _shaderID = 0;
    }
}


GLuint Shader::getShaderID() const {
    return _shaderID;
}

void Shader::setSource(const string &source) {
    _source = source;
    createShader();
}





