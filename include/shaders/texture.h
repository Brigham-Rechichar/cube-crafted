#pragma once
#include "../../src/config.h"



class Texture{

    public:

    GLuint ID;
    unsigned int type;

    /**
     * param imagePath,textType,slot,format,pixelType
     */
    Texture(const char* imagePath, unsigned int texType, unsigned int slot, unsigned int format, unsigned int pixelType);


    void texUnit(GLuint shaderProgram, const char* uniform, GLuint unit);


    void Bind();


    void Unbind();

    
    void Delete();

};