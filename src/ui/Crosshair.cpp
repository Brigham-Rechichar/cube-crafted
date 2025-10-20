#include "../../include/ui/Crosshair.h"

Crosshair::Crosshair(const char* texturePath, int screenWidth, int screenHeight, float size)
    :texture(texturePath, GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE),
    shader("../src/graphics/gui_shaders/crosshair_Vertex.glsl", "../src/graphics/gui_shaders/crosshair_Fragment.glsl"),
    size(size)
{
// Quad vertices in NDC (centered on screen)
    float vertices[] = {
        // positions     // UVs
        -size, -size,    0.0f, 0.0f,
         size, -size,    1.0f, 0.0f,
         size,  size,    1.0f, 1.0f,
        -size,  size,    0.0f, 1.0f
    };

    unsigned int indices[] = { 0, 1, 2, 2, 3, 0 };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    unsigned int EBO;
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Crosshair::Draw(){
    glDisable(GL_DEPTH_TEST); // draw over world
    shader.use();
    texture.Bind();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glEnable(GL_DEPTH_TEST);
}
void Crosshair::Delete(){
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    texture.Delete();
    shader.Delete();
}