#pragma once

// Include matrix libs and camera
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "entities/camera.h"

class Player {
    public:
        // Instantiate player at relative pos
        explicit Player(glm::vec3 startPos = {0.0f, 0.0f, 0.0f});

        void attachCamera(Camera& cam);
        void update(GLFWwindow* win, float dt);


        float moveSpeed = 4.0f;
        float sprintSpeed = 7.0f;
        float gravity = -20.0f;
        float jumpVel = 7.0f;
        float eyeHeight = 1.8f;
        float groundY = 0.0f;

        glm::vec3 position{};
        glm::vec3 velocity{};
        bool grounded = false;

    private:

        Camera* cam = nullptr;

        void handleInput(GLFWwindow* win, float dt);
        void integrate(float dt);
        void collideWithGround();
};
