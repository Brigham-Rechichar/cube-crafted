#include "entities/Player.h"
#include "entities/camera.h"
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

    // Use forward / right vectors to initiate forward movement
    glm::vec3 fwd = glm::normalize(glm::vec3(cam->getPosition() + glm::vec3(0.0f) - cam->getPosition()));

    cam->Inputs(win);

    // Jump motion executes if grounded
    if (grounded && glfwGetKey(win, GLFW_KEY_SPACE) == GLFW_PRESS) {
        grounded = false;
        velocity.y = jumpVel;
    }
}
