#include "../../include/world/block.h"


block::block(BlockType type, glm::vec3 position){
    this->type=type;
    this->position=position;
}
void block::draw(Shader& shader){
    //create model matrix for this block
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);

    //setting the shader
    shader.setMat4("model", model);

    //drawing the cube
    mesh.draw();
}