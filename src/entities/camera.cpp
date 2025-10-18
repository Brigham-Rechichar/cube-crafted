#include "../../include/entities/camera.h"

//initilizing the camera
Camera::Camera(
    glm::vec3 startPos,
    glm::vec3 startUp,
    float startYaw,
    float startPitch){

    position = startPos;
    worldUp  = startUp;                  // store worldUp, not up
    yaw      = startYaw;
    pitch    = startPitch;
    speed    = 2.5f;
    sensitivity = 0.1f;
    front    = glm::vec3(0.0f, 0.0f, -1.0f);  // <-- FIXED (look down -Z)
    UpdateCameraVectors();
}

//3D matrix representing the world from a specific camera's perspective
glm::mat4 Camera::getViewMatrix() const{
    return glm::lookAt(position, position + front, up);
}

void Camera::processKeyboard(char direction, float deltaTime){
    float velocity = speed * deltaTime;
    if (direction == 'W') position += front * velocity;
    if (direction == 'S') position -= front * velocity;
    if (direction == 'A') position -= right * velocity;
    if (direction == 'D') position += right * velocity;
}

void Camera::processMouseMovement(float xoffset, float yoffset){
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    UpdateCameraVectors();
}

void Camera::UpdateCameraVectors(){
    glm::vec3 f;
    f.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    f.y = sin(glm::radians(pitch));
    f.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(f);
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}



