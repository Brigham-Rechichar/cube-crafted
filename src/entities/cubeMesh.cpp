#include "../../include/entities/cubeMesh.h"

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