//
// Created by huxf on 2016/8/25.
//

#include "texture_manager.h"

namespace magic {

    template<> TextureManager *Singleton<TextureManager>::instance_ = nullptr;

    TextureManager::TextureManager() {

    }

    TextureManager::~TextureManager() {

    }

}