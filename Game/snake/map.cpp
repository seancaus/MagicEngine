//
// Created by huxf on 2016/8/22.
//

#include "map.h"
#include <SOIL/SOIL.h>

namespace magic {

    Map::Map() :
            _vao(0),
            _vbo(0) {
        _program = make_shared<GPUProgram>("../Assets/glsl/map.vert", "../Assets/glsl/map.frag");
    }

    Map::~Map() {
        this->destroy();
    }

    void Map::destroy() {
        if (_vao) {
            glDeleteVertexArrays(1, &_vao);
            _vao = 0;
        }

        if (_vao) {
            glDeleteBuffers(1, &_vbo);
            _vbo = 0;
        }
    }

    void Map::preBind() {
        destroy();

        float verteies[] = {
                -1, -1, 1, 1, -1, 1, 1, -1, 0, 0, 1, 1, 0, 1, 1, 0
        };
        int indeices[] = {0, 1, 2, 0, 3, 1};

        glGenVertexArrays(1, &_vao);
        glGenBuffers(1, &_vbo);

        glBindVertexArray(_vao);
        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(verteies), verteies, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (GLvoid *) 0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (GLvoid *) (8 * sizeof(float)));

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        glGenBuffers(1, &_ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeices), indeices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 1);

        int w, h;
        unsigned char *image = SOIL_load_image("../Assets/Textures/snake/grasstextures19.jpg", &w, &h, 0,
                                               SOIL_LOAD_RGBA);
        glGenTextures(1, &_tex);
        glGenTextures(1, &_pbo);
        glBindTexture(GL_TEXTURE_2D, _tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glBindBuffer(GL_PIXEL_UNPACK_BUFFER, _pbo);
        glBufferData(GL_PIXEL_UNPACK_BUFFER, w * h * 4, NULL, GL_STREAM_READ);
        GLubyte *ptr = (GLubyte *) glMapBuffer(GL_PIXEL_UNPACK_BUFFER, GL_WRITE_ONLY);
        if (ptr) {
            memcpy(ptr, image, w * h * 4);
            glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);
        }
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
        glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
        SOIL_free_image_data(image);
    }


    int Map::rand(int min, int max)
    {
        static int seed = time(NULL);
        srand(seed);
        return (min + ::rand() % (max - min +1));
    }


    void Map::createFood()
    {
        rand(0,4);

    }

    void Map::draw() {
        _program->use();
        glBindTexture(GL_TEXTURE_2D, _tex);
        _program->setUniform1i("texSampler", 0);
        glBindVertexArray(_vao);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}