#include "../../src/config.h"

class block {
public:
    block();
    void draw();
    ~block();
private:
    unsigned int VAO, VBO;
};
