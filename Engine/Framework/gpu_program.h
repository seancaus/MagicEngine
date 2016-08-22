//
// Created by huxf on 2016/8/19.
//

#ifndef MAGIC_GPUPROGRAM_H
#define MAGIC_GPUPROGRAM_H


#include <iostream>
#include <GL/glew.h>

using namespace std;

namespace Magic {

    class GPUProgram {

    public:

        GPUProgram(const string &vertexFile, const string &fragmentFile, const string &geometryFile = "");

        virtual ~GPUProgram();

        void use();

        void setUniform1i(const string &name, unsigned int value);

    protected:

        void deleteProgram();

        GLuint createProgram(const string &vertexSource, const string &fragmentSource, const string &geometrySource);

        string read(const char *filePath);


        GLuint _programID;
    };
}

#endif //MAGIC_GPUPROGRAM_H
