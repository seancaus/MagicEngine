cmake_minimum_required(VERSION 3.5)
project(Magic)

MESSAGE("System is " ${CMAKE_SYSTEM_NAME})
MESSAGE("System is " ${PROJECT_SOURCE_DIR})

add_definitions(-DGLEW_STATIC)
#add_definitions(-D)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_CXX_FLAGS   "-g")                     # 调试信息
#set(CMAKE_CXX_FLAGS   "-Wall")                  # 开启所有警告
set(CMAKE_CXX_FLAGS_DEBUG   "-O0" )             # 调试包不优化
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG " )   # release包优化

INCLUDE_DIRECTORIES(./includes)


IF(APPLE)
	LINK_DIRECTORIES(./libs/apple)

    #SET(GUI_TYPE MACOSX_BUNDLE)
    FIND_LIBRARY(COCOA_LIBRARY Cocoa)
    FIND_LIBRARY(OPENGL_LIBRARY OpenGL)
    FIND_LIBRARY(COREVIDEO_LIBRARY CoreVideo)
    FIND_LIBRARY(IOKIT_LIBRARY IOKit)

    MARK_AS_ADVANCED (COCOA_LIBRARY
            OPENGL_LIBRARY
            COREVIDEO_LIBRARY
            IOKIT_LIBRARY
            )
    SET(EXTRA_LIBS ${COCOA_LIBRARY} ${OPENGL_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY} )
ELSEIF(WIN32)
	LINK_DIRECTORIES(./libs/windows)
ENDIF (APPLE)

aux_source_directory(Engine/Framework SOURCE_FILES)
aux_source_directory(Engine/Plugin/RenderSystem/GL SOURCE_FILES)

aux_source_directory(Game SOURCE_FILES)

add_executable(Magic ${SOURCE_FILES} main.cpp)

IF(APPLE)
    TARGET_LINK_LIBRARIES(Magic ${EXTRA_LIBS} libGLEW.a libglfw3.a libSOIL.a libglog.a)
else(WIN32)
    TARGET_LINK_LIBRARIES(Magic libglew32.dll.a libglfw3.a libSOIL.a libopengl32.a libglu32.a)
ENDIF (APPLE)