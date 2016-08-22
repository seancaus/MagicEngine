//
// Created by huxf on 2016/8/19.
//

#include <iostream>
#include "vertex_shader.h"

namespace Magic {

    VertexShader::VertexShader(string source) :
            Shader(source) {
        createShader();
    }

    VertexShader::~VertexShader() {
    }

    GLuint VertexShader::createShader() {
        if (_source.empty()) {
            cout << "Source Is nullptr or Empty" << endl;
            return 0;
        }

        deleteShader();

        GLint success;
        GLchar infoLog[512];
        _shaderID = glCreateShader(GL_VERTEX_SHADER);
        const GLchar *codeString = _source.c_str();
        glShaderSource(_shaderID, 1, &codeString, nullptr);
        glCompileShader(_shaderID);
        glGetShaderiv(_shaderID, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(_shaderID, 512, nullptr, infoLog);
            cout << "ERROR Compile Vertex Shader " << infoLog << endl;
            return 0;
        }

        return _shaderID;
    }
}