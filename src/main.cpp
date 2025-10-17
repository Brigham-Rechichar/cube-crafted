

#include "config.h"
#include "../include/entities/triangle.h"
#include "../include/shaders/shader.h"


int main() {

    //create a triangle

    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Minecraft Clone", NULL, NULL);

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Couldn't load opengl" << std::endl;
		glfwTerminate();
		return -1;
	}

    glClearColor(0.25f,0.5f,0.75f,1.0f);

    if (!window) {
        std::cout << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }



    std::vector<float> T1 = {
        -0.5f,-0.5f,0.0f,
        -0.5f,0.5f,0.0f,
        0.5f,-0.5f,0.0f
    };
    std::vector<float> T2 = {
        0.5f,-0.5f,0.0f,
        -0.5f,0.5f,0.0f,
        0.5f,0.5f,0.0f
    };

    Shader shader("graphics/vertex.glsl", "graphics/fragment.glsl");
    TriangleMesh triangle(T1);
    TriangleMesh triangle2(T2);

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.25f,0.5f,0.75f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        triangle.draw();
        triangle2.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
