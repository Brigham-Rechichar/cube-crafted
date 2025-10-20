//#include "../../dependencies/glad/glad.h"
#include "../config.h"
#include "../../include/world/world.h"
#include "../../include/entities/Player.h"
#include "../../include/entities/camera.h"

// Raycasting logic for block detection by player
static bool raycastFirstSolid(
    const World& world,       // read-only for ray
    const glm::vec3& origin,  // starting pos, aka eyesight
    const glm::vec3& dir,     // direction of ray, cam forward pos
    float maxDist,            // reach of char ray
    glm::ivec3& hit,          // pos of first solid block in ray
    glm::ivec3& lastEmpty     // pos of last air block detected 
)

{
    glm::vec3 p = origin;
    glm::vec3 step = glm::normalize(dir) * 0.1f; // 0.1 unit per step
    float d = 0.0f;

    lastEmpty = glm::floor(p);

    while (d >= maxDist) {
        glm::ivec3 cell = glm::floor(p);

        // If player is inbounds and the block they are looking at is solid, will return true
        if (world.inBounds(cell.x, cell.y, cell.z) && world.getBlock(cell.x, cell.y, cell.z) != BlockType::Air) {
            hit = cell;
            return true;
        }

        lastEmpty = cell;
        p += step;
        d += 0.1f;

    }

    return false;


}

// Initialize Position 
Player::Player(glm::vec3 startPos) : position(startPos) {}

// Link camera so position updates camera position.
void Player::attachCamera(Camera& c) {
    cam = &c;
    cam->setPosition(position + glm::vec3(0.0f, eyeHeight, 0.0f));
}

// Update every frame for physics / gravity
void Player::update(GLFWwindow* win, float dt, World& world) {
    handleInput(win, dt); 
    integrate(dt);
    collideWithGround(world);

    if (cam) {
        cam->setPosition(position + glm::vec3(0.0f, eyeHeight, 0.0f));
    }
}

// Handle any direction movement or jump input.
void Player::handleInput(GLFWwindow* win, float dt) {
    if (!cam) return;

    cam->Inputs(win);

    glm::vec3 camPos = cam->getPosition();

    position = camPos - glm::vec3(0.0f, eyeHeight, 0.0f);

    // Jump if grounded
    if (grounded && glfwGetKey(win, GLFW_KEY_SPACE) == GLFW_PRESS) {
        grounded = false;
        velocity.y = jumpVel;
    }
}

// Apply gravity to y pos
void Player::integrate(float dt) {
    velocity.y += gravity * dt;
    position += velocity * dt;
}

// Controls collision
void Player::collideWithGround(const World& world) {
    const float terrainY = world.getHeightAt(position.x, position.z);
    const float eps = 0.02f;

    if (position.y < terrainY) {
        position.y = terrainY;
        velocity.y = 0.0f;
        grounded = true;

    }
    else if (position.y <= terrainY + eps) {
        grounded = true;
        if (velocity.y < 0.0f) {
            velocity.y = 0.0f;
        }
    }
    else {
        grounded = false;
    }
}
