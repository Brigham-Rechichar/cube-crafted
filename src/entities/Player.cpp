#include "../../dependencies/glad/glad.h"
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
void Player::update(GLFWwindow* win, float dt) {
    handleInput(win, dt); 
    integrate(dt);
    collideWithGround();

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
void Player::collideWithGround() {
    float feetY = position.y;
    
    if (feetY < groundY) {
        position.y = groundY;
        velocity.y = 0.0f;
        grounded = true;
    }
    else {
        grounded = false;
    }
}
