//
// Created by huxf on 2016/8/25.
//

#ifndef MAGIC_TEXTURE_MANAGER_H
#define MAGIC_TEXTURE_MANAGER_H

#include "singleton.h"

namespace magic{

    class TextureManager:public Singleton<TextureManager>
    {
    public:

        TextureManager();
        virtual ~TextureManager();

    protected:

    };
}

#endif //MAGIC_TEXTURE_MANAGER_H
