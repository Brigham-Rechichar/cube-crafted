#pragma once
#include <vector>


class TriangleMesh {
public:
TriangleMesh( std::vector<float> vertices);
void draw();
~TriangleMesh();

private:
unsigned int VBO, VAO, vertex_count;
};