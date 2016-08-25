//
// Created by huxf on 2016/8/19.
//

#include <iostream>
#include "fragment_shader.h"

namespace magic {
    FragmentShader::FragmentShader(const string &source) :
            Shader(source) {
        createShader();
    }

    GLuint FragmentShader::createShader() {
        if (_source.empty()) {
            cout << "Source Is Empty" << endl;
            return 0;
        }

        deleteShader();

        GLint success;
        GLchar infoLog[512];
        _shaderID = glCreateShader(GL_FRAGMENT_SHADER);
        const GLchar *codeString = _source.c_str();
        glShaderSource(_shaderID, 1, &codeString, nullptr);
        glCompileShader(_shaderID);
        glGetShaderiv(_shaderID, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(_shaderID, 512, nullptr, infoLog);
            cout << "ERROR Compile Fragment Shader " << infoLog << endl;
            return 0;
        }

        return _shaderID;
    }
}


