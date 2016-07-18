cmake_minimum_required(VERSION 3.5)
project(MagicCube)

MESSAGE("System is " ${CMAKE_SYSTEM_NAME})

add_definitions(-DGLEW_STATIC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

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
aux_source_directory(src SOURCE_FILES)

add_executable(MagicCube ${SOURCE_FILES} main.cpp)

IF(APPLE)
    TARGET_LINK_LIBRARIES(MagicCube ${EXTRA_LIBS} libGLEW.a libglfw3.a libSOIL.a libglog.a)
else(WIN32)
    TARGET_LINK_LIBRARIES(MagicCube libglew32.dll.a libglfw3.a libSOIL.a libopengl32.a libglu32.a)
ENDIF (APPLE)