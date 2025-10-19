#pragma once
#include "../../src/config.h"
#include "../entities/cubeMesh.h"
#include "../shaders/shader.h"

enum class BlockType { Air, Dirt, Grass, Stone };


class block{

    BlockType type;
    glm::vec3 position;
    bool active;
    cubeMesh mesh;

    block(BlockType type, glm::vec3 position);
    void draw(Shader& shader);

};