//
// Created by huxf on 2016/8/25.
//

#include <iostream>
#include <SOIL/SOIL.h>
#include "texture.h"

using namespace std;

namespace magic
{

    Texture::Texture():
    _textureID(0)
    ,_width(0)
    ,_height(0)
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
        if(!glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER))
        {
            cout << "Can't Write Buffer" << endl;
        }

        glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
        glDeleteBuffers(1,&pbo);
        SOIL_free_image_data(data);

        return _textureID;
    }

}