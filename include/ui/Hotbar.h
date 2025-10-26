#pragma once
#include "../../src/config.h"
#include "../shaders/shader.h"

enum class ItemID : int { Dirt=0, Grass=1, Stone=2, Empty=3 };

class Hotbar {
    private:

        GLuint vao=0, vbo=0;
        int W=0, H=0;
        float slotPx = 64.0f, padPx = 8.0f;

        glm::mat4 slotModel(int i) const;

    public:
        int selected = 0;
        ItemID items[7] = { ItemID::Dirt, ItemID::Grass, ItemID::Stone, ItemID::Empty, ItemID::Empty, ItemID::Empty, ItemID::Empty };

        void init(int winW, int winH);
        void resize(int winW, int winH);
        void draw(Shader& shader);
        ItemID current() const { return items[selected]; }

}