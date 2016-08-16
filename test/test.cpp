//
// Created by huxf on 2016/8/15.
//

#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "SOIL/SOIL.h"

using namespace std;

const GLchar * vertexCode = "#version 330 core\n"
        "layout(location = 0)in vec4 pos;\n"
"void main(){\n"
"gl_Position = pos;\n"
"}\n";

const GLchar * fragmentCode = "#version 330 core\n"
"out vec4 color;\n"
"void main(){\n"
"color = vec4(.5,.5,.5,1);\n"
"}\n";

int main(int argc, char **argv)
{

    if ( !glfwInit() )
    {
        cout << "glfwInit failed" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(300,300,"test", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if(GLEW_OK != glewInit())
    {
        cout << "glewInit failed" << endl;
        glfwTerminate();
        return -1;
    }

    int w,h;
    glfwGetFramebufferSize(window,&w,&h);
    glViewport(0,0,w,h);

    GLuint buffer,vertexArray,elementBuffer;
    glGenVertexArrays(1,&vertexArray);
    glGenBuffers(1,&buffer);
    glGenBuffers(1,&elementBuffer);

    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER,buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,elementBuffer);

    GLint success;
    GLchar infoLog[512];
    float vertexData[] = {
            0, 0.5,0,1,
            -.5, -.5,0,1,
            .5, -.5,0,1
    };
    int indexs[] = {0,1,2};
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexData),vertexData,GL_STATIC_DRAW);
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE, sizeof(GLfloat)*4,(GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indexs),indexs,GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexCode, nullptr);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader,512,nullptr,infoLog);
        cout << "error:" << infoLog << endl;
        return -1;
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentCode,nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShader,512,nullptr,infoLog);
        cout << "fragment Error:" << infoLog << endl;
        return -1;
    }

    GLuint program = glCreateProgram();
    glAttachShader(program,vertexShader);
    glAttachShader(program,fragmentShader);
    glLinkProgram(program);
    glGetProgramiv(program,GL_LINK_STATUS,&success);
    if(!success)
    {
        glGetProgramInfoLog(program,512,nullptr,infoLog);
        cout << "Program Link Error:" << infoLog << endl;
        return -1;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    while( !glfwWindowShouldClose(window) )
    {
        glfwPollEvents();

        glClearColor(.0,.0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);

        glBindVertexArray(vertexArray);
        glDrawArrays(GL_TRIANGLES,0,3);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    cout << "test" << endl;
    return 0;
}