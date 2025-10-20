

#include "config.h"
#include "../include/entities/Player.h"
#include "../include/entities/triangle.h"
#include "../include/shaders/shader.h"
#include"../include/entities/cubeMesh.h"
#include"../include/entities/camera.h"
#include "../include/world/world.h"

int main() {


    // Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW\n";
        return -1;
    }

    int width =800;
    int height =600;
    GLFWwindow* window = glfwCreateWindow(width, height, "Minecraft Clone", NULL, NULL);

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Couldn't load opengl" << std::endl;
		glfwTerminate();
		return -1;
	}

    if (!window) {
        std::cout << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }

    glEnable(GL_DEPTH_TEST);


    Shader shader("../src/graphics/vertex.glsl", "../src/graphics/fragment.glsl");


    Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

    Player player(glm::vec3(0.5f, 5.0f, 0.5f));
    player.attachCamera(camera);

    float currentFrame;
    float lastFrame=0.0f;

    World world(16,16,8);
    world.generate();

    while (!glfwWindowShouldClose(window)) {
        float currentFrame = glfwGetTime();
        float dt = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glClearColor(0.25f,0.5f,0.75f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.use();

        player.update(window, dt, world);
        camera.Matrix(45.0f, 0.1f, 100.0f, shader, "camMatrix");
        camera.Inputs(window);

        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f));
        shader.setMat4("model", model);
        world.draw(shader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
