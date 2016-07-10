//
// Created by Ziv on 16/6/18.
//

#ifndef MAGICCUBE_SHADER_H
#define MAGICCUBE_SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Shader {


public:
    Shader();
    Shader(const char* vertexPath,const char* fragmentPath);

    void use();

    void setMatrix4(const char* name,glm::mat4 value);
    void setVector3f(const char* name, GLfloat x,GLfloat y,GLfloat z);

protected:
    std::string readCode(char const* vertexPath);

    GLuint _program;
};


#endif //MAGICCUBE_SHADER_H
