#include "../../include/entities/cubeMesh.h"

cubeMesh::cubeMesh() {

    // define default cube vertices
    std::vector<float> vertices = {
    // --- Front face (z = +0.5)
    -0.5f, -0.5f,  0.5f,  // bottom-left
     0.5f, -0.5f,  0.5f,  // bottom-right
     0.5f,  0.5f,  0.5f,  // top-right
     0.5f,  0.5f,  0.5f,  // top-right
    -0.5f,  0.5f,  0.5f,  // top-left
    -0.5f, -0.5f,  0.5f,  // bottom-left

    // --- Back face (z = -0.5)
    -0.5f, -0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

    // --- Left face (x = -0.5)
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

    // --- Right face (x = +0.5)
     0.5f,  0.5f,  0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,

    // --- Top face (y = +0.5)
    -0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,

    // --- Bottom face (y = -0.5)
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f
};

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

cubeMesh::cubeMesh(std::vector<float> cubeVertices){

    //generating buffers for the cube
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    //biding the buffers
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //allocating memory for the VBO
    glBufferData(GL_ARRAY_BUFFER, cubeVertices.size()*sizeof(float), cubeVertices.data(), GL_STATIC_DRAW);

    //setting vertex perameters 
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


void cubeMesh::draw(){
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}

cubeMesh::~cubeMesh(){
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}