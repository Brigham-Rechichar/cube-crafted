

#pragma once
#include "../../src/config.h"
#include "../shaders/shader.h"

class Camera{
    glm::vec3 Position;
    glm::vec3 Orientation = glm::vec3 (0.0f,0.0f,-1.0f);
    glm::vec3 Up = glm::vec3 (0.0f,1.0f,0.0f);

    bool firstClick;

    int Wwidith;
    int Wheight;

    float speed = 0.1f;
    float sensitivity = 100.0f;

    public:
    //initilizes the camera
    Camera(int width, int height, glm::vec3 position);

    // Updates and exports the camera matrix to the Vertex Shader
	void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);

	// Handles camera inputs
	void Inputs(GLFWwindow* window);

    // Setter & Getter for Position
    void setPosition(const glm::vec3& pos) { Position = pos; }
    glm::vec3 getPosition() const { return Position; }

    glm::vec3 getOrientation() const { return Orientation; }
};