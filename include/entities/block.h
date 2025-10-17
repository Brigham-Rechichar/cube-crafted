#include "../../src/config.h"

class cubeMesh {
public:
    cubeMesh(std::vector<float>);
    void draw();
    ~cubeMesh();
private:
    unsigned int VAO, VBO;
};
