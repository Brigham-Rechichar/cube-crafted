#include "../../src/config.h"
#include "../shaders/shader.h"
#include "../shaders/texture.h"

class Crosshair{
    unsigned int VAO,VBO;
    Texture texture;
    Shader shader;
    float size; 
    
    public:

    Crosshair(const char* texturePath, int screenWidth, int screenHeight, float size = 0.05f);
    void Draw();
    void Delete();

};