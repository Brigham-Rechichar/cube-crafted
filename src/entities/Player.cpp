//#include "../../dependencies/glad/glad.h"
#include "../../include/world/world.h"
#include "../../include/entities/Player.h"
#include "../../include/entities/camera.h"
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Initialize Position 
Player::Player(glm::vec3 startPos) : position(startPos) {}


// Link camera so position updates camera position.
void Player::attachCamera(Camera& c) {
    cam = &c;
    cam->setPosition(position + glm::vec3(0.0f, eyeHeight, 0.0f));
}

// Update every frame for physics / gravity
void Player::update(GLFWwindow* win, float dt, const World& world) {
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
