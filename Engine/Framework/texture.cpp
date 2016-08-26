//
// Created by huxf on 2016/8/25.
//

#include <iostream>
#include <SOIL/SOIL.h>
#include "texture.h"

using namespace std;

namespace magic
{

    Texture::Texture(shared_ptr<GPUProgram> program):
    _textureID(0)
    ,_width(0)
    ,_height(0)
    ,_program(program)
    {
    }

    Texture::~Texture()
    {
        destroy();
    }


    void Texture::destroy()
    {
        if (_textureID)
        {
            glDeleteTextures(1,&_textureID);
            _textureID = 0;
        }
    }


    void Texture::bindSampler2D(const string& name,unsigned int unit)
    {
        glActiveTexture(GL_TEXTURE0 + unit);
        glBindTexture(GL_TEXTURE_2D,_textureID);
        _program->setUniform1i(name.c_str(),unit);
    }

    GLuint Texture::loadTexture(const string &name)
    {
        glGenTextures(1, &_textureID);
        glBindTexture(GL_TEXTURE_2D, _textureID);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
        glGenerateMipmap(GL_TEXTURE_2D);

        GLubyte* data = SOIL_load_image(name.c_str(),&_width,&_height,NULL,SOIL_LOAD_RGBA);
        int dataSize = _width * _height * 4;

        GLuint pbo;
        glGenBuffers(1, &pbo);
        glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pbo);
        glBufferData(GL_PIXEL_UNPACK_BUFFER,dataSize,NULL,GL_STREAM_READ);
        GLubyte* ptr = (GLubyte*)glMapBuffer(GL_PIXEL_UNPACK_BUFFER,GL_WRITE_ONLY);
        if(!ptr)
        {
            cout << "MapBuffer Error" << endl;
            glDeleteBuffers(1,&pbo);
            SOIL_free_image_data(data);
            return 0;
        }

        memcpy(ptr,data,dataSize);
        if(glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER))
        {
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,_width,_height,0,GL_RGBA,GL_UNSIGNED_BYTE,NULL);
        } else
        {
            cout << "Can't Write Buffer" << endl;
        }

        glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
        glDeleteBuffers(1,&pbo);
        SOIL_free_image_data(data);
        glBindTexture(GL_TEXTURE_2D, 0);
        return _textureID;
    }

    GLuint Texture::getTextureID() const
    {
        return _textureID;
    }


}