#version 330 core

layout (location = 0) in vec3 aPos;

//takes in the camera matrix from the main
uniform mat4 camMatrix;

void main()
{
    //outputs the position
    gl_Position = camMatrix * vec4(aPos, 1.0);
}
