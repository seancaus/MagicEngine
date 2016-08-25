//
// Created by huxf on 2016/8/25.
//

#ifndef MAGIC_TEXTURE_H
#define MAGIC_TEXTURE_H

#include <string>
#include <GL/glew.h>

using namespace std;

namespace magic
{

    class Texture
    {

    public:

        Texture();
        virtual ~Texture();

        GLuint loadTexture(const string& name);

    protected:

        void destroy();

        GLuint _textureID;

        int _width;
        int _height;

    };
}

#endif //MAGIC_TEXTURE_H
