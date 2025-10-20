#include "../../include/shaders/texture.h"



//default constructor that creates a texture for an object
Texture::Texture(const char* imagePath, unsigned int texType, unsigned int slot, unsigned int format, unsigned int pixelType){

    type = texType;                // store the type for later
    glGenTextures(1, &ID);         // generate an OpenGL texture object
    glActiveTexture(slot);         // activate the texture unit (GL_TEXTURE0, etc.)
    glBindTexture(texType, ID);    // bind the texture so we can modify it

    // set filtering and wrapping rules
    glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // load image pixels into memory (using stb_image)
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* bytes = stbi_load(imagePath, &width, &height, &nrChannels, 0);

    if (!bytes) {
    std::cerr << "❌ Failed to load texture at path: " << imagePath << std::endl;
    } else {
        std::cout << "✅ Loaded texture " << imagePath 
                << " (" << width << "x" << height 
                << ", " << nrChannels << " channels)" << std::endl;
    }

    // send image data to GPU
    glTexImage2D(texType, 0, GL_RGBA, width, height, 0, format, pixelType, bytes);
    glGenerateMipmap(texType);     // create mipmaps for better scaling

    stbi_image_free(bytes);        // free CPU-side memory
    glBindTexture(texType, 0);     // unbind texture to prevent accidental edits
}


void Texture::texUnit(GLuint shaderProgram, const char* uniform, GLuint unit){
    GLuint texUni = glGetUniformLocation(shaderProgram, uniform); // find uniform in shader
    glUniform1i(texUni, unit);                                    // assign texture unit index
}


void Texture::Bind(){
    glBindTexture(type,ID);
}


void Texture::Unbind(){
    glBindTexture(type,0);
}

void Texture::Delete(){
    glDeleteTextures(1,&ID);
}