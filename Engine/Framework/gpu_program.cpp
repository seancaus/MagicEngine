//
// Created by huxf on 2016/8/19.
//

#include <sstream>
#include <fstream>
#include "gpu_program.h"
#include "vertex_shader.h"
#include "fragment_shader.h"

namespace magic {

    GPUProgram::GPUProgram(const string &vertexFile, const string &fragmentFile, const string &geometryFile) :
            _programID(0)
            ,_uboPoint(0)
    {
        string vertexSource = read(vertexFile.c_str());
        string fragmentSource = read(fragmentFile.c_str());
        string geometrySource("");
        if (!geometryFile.empty()) {
            geometrySource = read(geometryFile.c_str());
        }

        createProgram(vertexSource, fragmentSource, geometrySource);
    }

    GPUProgram::~GPUProgram() {
        deleteProgram();
    }

    void GPUProgram::deleteProgram() {
        if (_programID) {
            glDeleteProgram(_programID);
            _programID = 0;
        }
    }

    GLuint GPUProgram::createProgram(const string &vertexSource, const string &fragmentSource,
                                     const string &geometrySource) {
        VertexShader vshader(vertexSource);
        FragmentShader fshader(fragmentSource);

        GLint success;
        GLchar infoLog[512];
        _programID = glCreateProgram();
        glAttachShader(_programID, vshader.getShaderID());
        glAttachShader(_programID, fshader.getShaderID());
        glLinkProgram(_programID);
        glGetProgramiv(_programID, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(_programID, 512, nullptr, infoLog);
            cout << "ERROR Link Program " << infoLog << endl;
            return 0;
        }
        return _programID;
    }

    void GPUProgram::use()
    {
        glUseProgram(_programID);
    }

    void GPUProgram::bindUniformBuffer(const string& uniformBlockName,const GLuint& uniformBufferObject)
    {
        GLuint index = glGetUniformBlockIndex(_programID,uniformBlockName.c_str());
        glUniformBlockBinding(_programID,index,_uboPoint);

        glBindBufferBase(GL_UNIFORM_BUFFER,_uboPoint,uniformBufferObject);
//        glBindBufferRange();
        ++_uboPoint;
    }



    void GPUProgram::setUniform1i(const string &name, unsigned int value)
    {
        GLint local = glGetUniformLocation(_programID, name.c_str());
        glUniform1i(local, value);
    }

    void GPUProgram::setUniform2f(const string &name, const GLfloat v1,const GLfloat v2)
    {
        GLint local = glGetUniformLocation(_programID, name.c_str());
        glUniform2f(local,v1,v2);
    }

    string GPUProgram::read(const char *filePath)
    {
        string codeString("");
        try {
            stringstream stream;

            // 打开文件
            ifstream file(filePath);
            // 读取文件缓冲到流
            stream << file.rdbuf();

            // 关闭文件句柄
            file.close();

            // 将流转为GLchar数组
            codeString = stream.str();
        }
        catch (std::exception e)
        {
            cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
        }
        return codeString;
    }
}