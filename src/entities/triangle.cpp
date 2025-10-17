#include "../../include/entities/triangle.h"
#include "../config.h"


//constructor for triangle mesh
TriangleMesh::TriangleMesh(std::vector<float> vertices){
   
    vertex_count = 3;

    //generating the VBO and VAO
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);


    //binding the VAO
    glBindVertexArray(VAO);

    //binding the VBO aand filling it vith vertext value
    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Tell OpenGL how to interpret the vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    // Unbind to avoid accidental changes
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

//function for drawing the triangle
void TriangleMesh::draw(){
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertex_count);
    glBindVertexArray(0);
}

//deconstructor for TriangleMesh
TriangleMesh::~TriangleMesh(){
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}



