
#include "../../include/world/world.h"

World::World(int width, int depth, int height)
    : width(width), depth(depth), height(height) {}

void World::generate(){
    
    blocks.reserve(width * depth * height);

    for (int x = 0; x < width; ++x) {
        for (int z = 0; z < depth; ++z) {
            for(int y=0;y<height;y++){
                glm::vec3 pos(x, y, z);
                blocks.emplace_back(BlockType::Grass, pos);
            }
        }
    }
}

void World::draw(Shader& shader){
    for(block& b:blocks){
        b.draw(shader);
    }
}

float World::getHeightAt(float x, float z) const {

    int xi = (int)floor(x);
    int zi = (int)floor(z);

    if (xi < 0 || xi >= width || zi < 0 || zi >= depth) {
        return 0.0f;
    }

    for (int y = height - 1; y >= 0; --y) {
        const block& b = blocks[getIndex(xi, y, zi)];
        if (b.isSolid()) {
            return float(y + 1);
        }
    }

    return 0.0f;
}
