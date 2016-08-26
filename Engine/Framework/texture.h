//
// Created by huxf on 2016/8/25.
//

#ifndef MAGIC_TEXTURE_H
#define MAGIC_TEXTURE_H

#include <string>
#include <GL/glew.h>
#include <memory>
#include "gpu_program.h"

using namespace std;

namespace magic
{

    class Texture
    {

    public:

        Texture(shared_ptr<GPUProgram> program);
        virtual ~Texture();

        GLuint loadTexture(const string& name);
        GLuint getTextureID() const;
        void bindSampler2D(const string& name,unsigned int unit = 0);

    protected:

        void destroy();

        int _width;
        int _height;

        GLuint _textureID;
        shared_ptr<GPUProgram> _program;
    };
}

#endif //MAGIC_TEXTURE_H
