

#pragma once
#include "../../src/config.h"

class Camera{
    public:
        glm::vec3 position;
        glm::vec3 front;
        glm::vec3 up;
        glm::vec3 right;
        glm::vec3 worldUp;

        float yaw;
        float pitch;
        float speed;
        float sensitivity;


        //constructor setting the starting position,yaw,and pitch
        Camera(
            glm::vec3 startPos = glm::vec3(0.0f,0.0f,3.0f),
            glm::vec3 startUp = glm::vec3(0.0f,1.0f,0.0f),
            float startYaw = -90.0f,
            float startPitch = 0.0f);

        glm::mat4 getViewMatrix() const;
        void processKeyboard(char direction, float deltaTime);
        void processMouseMovement(float xoffset, float yoffset);

    private:

        void UpdateCameraVectors();
};