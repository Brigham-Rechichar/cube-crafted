#pragma once
#include "../../src/config.h"

class cubeMesh {
public:
    cubeMesh(std::vector<float>);
    cubeMesh();
    void draw();
    ~cubeMesh();
private:
    unsigned int VAO, VBO;
};
