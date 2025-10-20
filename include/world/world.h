#pragma once
#include "../../src/config.h"
#include "block.h"

class World{
    int width,depth,height;
    std::vector<block> blocks;

public:
    World(int width = 16, int depth = 16, int height = 8);
    void generate();
    void draw(Shader& shader);

    inline int getIndex(int x, int y, int z) const { return x + width * (y + height * z); }

    float getHeightAt(float x, float z) const;

    // Block modification

    bool inBounds(int x, int y, int z) const; 
    BlockType getBlock(int x, int y, int z) const;
    void setBlock(int x, int y, int z, BlockType t);
    void removeBlock(int x, int y, int z) { setBlock(x, y, z, BlockType::Air);}

};