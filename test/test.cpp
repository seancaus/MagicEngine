#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "SOIL/SOIL.h"

using namespace std;

static const GLchar* vertexSource = "#version 330 core\n"
        "layout(location=0)in vec4 pos;\n"
        "layout(location=1)in vec2 inCoord;\n"
        "out vec2 coord;\n"
        "void main(){\n"
        "coord = inCoord;\n"
        "gl_Position = pos;\n"
"}";

static const GLchar* fragmentSource = "#version 330 core\n"
        "in vec2 coord;\n"
        "out vec4 color;\n"
        "uniform sampler2D samp1;\n"
        "uniform sampler2D samp2;\n"
        "void main(){\n"
        "color = mix(texture(samp1,coord),texture(samp2,coord),.5);\n"
"}";

int main1()
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(500,500,"test",nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    glewInit();
    int w,h;
    glfwGetFramebufferSize(window,&w,&h);
    glViewport(0,0,w,h);

    //------------------------------------------------------------------------
    GLuint vertexArray,vertexBuffer,texture[2];
    glGenVertexArrays(1,&vertexArray);
    glGenBuffers(1,&vertexBuffer);

    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer);

    float data[] = {.0,.5,0,1  ,-.5,-.5,.0,1  ,.5,-.5,.0,1
        ,.5,1   ,0,0    ,1,0
    };
    glBufferData(GL_ARRAY_BUFFER, sizeof(data),data,GL_STATIC_DRAW);
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,4* sizeof(float),(GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,2* sizeof(float),(GLvoid*)0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);

    //------------------------------------------------------------------------
    GLint success;
    GLchar infoLog[512];
    GLint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexSource, nullptr);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader,512,nullptr,infoLog);
        cout << "Compile Vertex Shader Error:" << infoLog << endl;
        return -1;
    }

    GLint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentSource, nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShader,512,nullptr,infoLog);
        cout << "Compile Fragment Shader Error:" << infoLog << endl;
        return -1;
    }

    GLint program = glCreateProgram();
    glAttachShader(program,vertexShader);
    glAttachShader(program,fragmentShader);
    glLinkProgram(program);
    glGetProgramiv(program,GL_LINK_STATUS,&success);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    if(!success)
    {
        glGetProgramInfoLog(program,512,nullptr,infoLog);
        cout << "Link Porgram Error:" << infoLog << endl;
        return -1;
    }

    //------------------------------------------------------------------------
    char* pics[2] = {"../Assets/Textures/1.jpg","../Assets/Textures/awesomeface.png"};
    glGenTextures(2,texture);
    for (int i = 0; i <2 ; ++i)
    {
        glBindTexture(GL_TEXTURE_2D,texture[i]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

        auto image = SOIL_load_image(pics[i],&w,&h,nullptr,SOIL_LOAD_RGBA);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,w,h,0,GL_RGBA,GL_UNSIGNED_BYTE,image);
        SOIL_free_image_data(image);
    }

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(.0,.0,.0,1);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);
        glBindVertexArray(vertexArray);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,texture[0]);
        auto locSamp1 = glGetUniformLocation(program,"samp1");
        glUniform1i(locSamp1,0);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D,texture[1]);
        auto locSamp2 = glGetUniformLocation(program,"samp2");
        glUniform1i(locSamp2,1);

        glDrawArrays(GL_TRIANGLES,0,3);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    return 0;
}