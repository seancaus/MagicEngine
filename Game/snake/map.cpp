//
// Created by huxf on 2016/8/22.
//

#include "map.h"
#include <SOIL/SOIL.h>
#include <stdlib.h>

namespace magic {

    Map::Map() :
            _vao(0),
            _vbo(0)
    {
        _program = make_shared<GPUProgram>("../Assets/glsl/map.vert", "../Assets/glsl/map.frag");
        _background = make_shared<Texture>(_program);
        _background->loadTexture("../Assets/Textures/snake/grasstextures19.jpg");
    }

    Map::~Map()
    {
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
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }


    int Map::rand(int min, int max)
    {
//        static int seed = time(NULL);
//        srand(seed);
//        return (min + ::rand() % (max - min +1));
        return 0;
    }


    void Map::createFood()
    {
        rand(0,4);

    }

    void Map::draw() {
        _program->use();
        _background->bindSampler2D("texSampler");

        glBindVertexArray(_vao);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}