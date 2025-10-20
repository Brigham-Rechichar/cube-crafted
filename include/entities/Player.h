#pragma once

// Include matrix libs and camera
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "camera.h"
#include "../world/world.h" 

class Player {
    public:
        // Instantiate player at relative pos
        explicit Player(glm::vec3 startPos = {0.0f, 0.0f, 0.0f});

        void attachCamera(Camera& cam); // Link Camera to player

        // Frame update to sync camera / physics
        void update(GLFWwindow* win, float dt, World& world); 


        // Movement presets
        float moveSpeed = 4.0f; // default 4.0
        float sprintSpeed = 9.0f;
        float gravity = -25.0f;
        float jumpVel = 8.5f; // default 8.5
        float eyeHeight = 1.8f;
        float groundY = 0.0f;


        glm::vec3 position{}; 
        glm::vec3 velocity{};
        bool grounded = false;

    private:

        Camera* cam = nullptr;

        // Handle input for movement / jumping
        void handleInput(GLFWwindow* win, float dt);


        // Update position considering gravity
        void integrate(float dt);


        // Collision checking
        void collideWithGround(const World& world);

        void tryBreak(World& world);
        void tryPlace(World& world);
        
};
