//
// Created by Ziv on 16/7/27.
//

#ifndef MAGIC_MAGIC_PLATFORM_H
#define MAGIC_MAGIC_PLATFORM_H

namespace Magic
{
    #define MAGIC_PLATFORM_UNDEF 0
    #define MAGIC_PLATFORM_WIN 1
    #define MAGIC_PLATFORM_APPLE 2
    #define MAGIC_PLATFORM_IOS 3
    #define MAGIC_PLATFORM_ANDROID 4
    #define MAGIC_PLATFORM_LINUX 5

    #if __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= 60000 || __IPHONE_OS_VERSION_MIN_REQUIRED >= 60000
        #define MAGIC_PLATFORM MAGIC_PLATFORM_IOS
    #else
        #define MAGIC_PLATFORM MAGIC_PLATFORM_APPLE
    #endif

}

#endif //MAGIC_MAGIC_PLATFORM_H