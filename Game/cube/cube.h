//
// Created by Ziv on 16/8/26.
//

#ifndef MAGIC_CUBE_H
#define MAGIC_CUBE_H

#include "../../Engine/Framework/gpu_program.h"
#include "cube_camera.h"

#include <memory>
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>

using namespace std;
using namespace magic;

class Cube
{

public:

    Cube(shared_ptr<CubeCamera>);
    virtual ~Cube();

    void updateCamera();
    void preBind();
    void draw();

protected:

    GLuint _vao,_vbo,_color_vbo,_model_vbo,_ebo,_ubo;

    vector<glm::mat4> _models;
    glm::mat4 _projection;

    shared_ptr<CubeCamera> _camera;
    shared_ptr<GPUProgram> _program;

};


#endif //MAGIC_CUBE_H
