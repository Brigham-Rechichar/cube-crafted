#pragma once
#include "../../src/config.h"

class Texture{

    public:

    GLuint ID;
    GLenum type;

    Texture(const char* imagePath, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);


    void texUnit(GLuint shaderProgram, const char* uniform, GLuint unit);


    void Bind();


    void Unbind();

    
    void Delete();

};