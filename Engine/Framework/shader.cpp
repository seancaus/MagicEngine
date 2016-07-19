//
// Created by Ziv on 16/6/18.
//

#include <GL/glew.h>
#include "shader.h"
//#include <glog/logging.h>

using namespace std;

Shader::Shader():
_program(0)
{
}

Shader::Shader(const char* vertexPath,const char* fragmentPath)
{
    GLint success;
    GLchar infoLog[512];

    string vertexCode = this->readCode(vertexPath);
    string fragmentCode = this->readCode(fragmentPath);

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const GLchar* vcode = vertexCode.c_str();
    glShaderSource(vertexShader,1,&vcode,nullptr);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader,512,nullptr,infoLog);
//        LOG(ERROR) << "Compile VertexShader:" << infoLog << endl;
        cout << "error："<< infoLog << endl;
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const GLchar* fcode = fragmentCode.c_str();
    glShaderSource(fragmentShader,1,&fcode,nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShader,512,nullptr,infoLog);
//        LOG(ERROR) << "Compile fragmentShader:" << infoLog << endl;
        cout << "error："<< infoLog << endl;
    }

    _program = glCreateProgram();
    glAttachShader(_program,vertexShader);
    glAttachShader(_program,fragmentShader);
    glLinkProgram(_program);
    glGetProgramiv(_program,GL_LINK_STATUS,&success);
    if(!success)
    {
        glGetProgramInfoLog(_program,512,nullptr,infoLog);
//        LOG(ERROR) << "Link Program:" << infoLog << endl;
        cout << "error："<< infoLog << endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::use()
{
    glUseProgram(_program);
}

void Shader::setMatrix4(const char *name, glm::mat4 value) {
    GLint loc = glGetUniformLocation(_program,name);
    glUniformMatrix4fv(loc,1,GL_FALSE,glm::value_ptr(value));
}

void Shader::setVector3f(const char *name, GLfloat x,GLfloat y,GLfloat z) {
    GLint loc = glGetUniformLocation(_program,name);
    glUniform3f(loc, x, y, z);
}

string Shader::readCode(const char* filePath)
{
    string code("");
    try {
        stringstream stream;

        // 打开文件
        ifstream file(filePath);
        // 读取文件缓冲到流
        stream << file.rdbuf();

        // 关闭文件句柄
        file.close();

        // 将流转为GLchar数组
        code = stream.str();
    }
    catch(std::exception e)
    {
//        LOG(ERROR) << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
    }
    return code;
}