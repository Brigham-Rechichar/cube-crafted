

#include "config.h"
#include "../include/entities/Player.h"
#include "../include/entities/triangle.h"
#include "../include/shaders/shader.h"
#include"../include/entities/cubeMesh.h"
#include"../include/entities/camera.h"
#include "../include/world/world.h"
#include "../include/shaders/texture.h"
#include "../include/ui/Crosshair.h"

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

    int width =800*2;
    int height =600*2;
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
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



    Shader shader("../src/graphics/vertex.glsl", "../src/graphics/fragment.glsl");


    Camera camera(width, height, glm::vec3(0.0f, 10.0f, 0.0f));

    Player player(glm::vec3(0.5f, 5.0f, 0.5f));
    player.attachCamera(camera);

    float currentFrame;
    float lastFrame=0.0f;

    World world(16,16,8);
    world.generate();
    
    Texture dirtTex(
        "../assets/pngwing.com.png",    // image path
        GL_TEXTURE_2D,                 // texture type
        GL_TEXTURE0,                   // texture unit slot
        GL_RGBA,                       // format
        GL_UNSIGNED_BYTE               // pixel type
    );
    dirtTex.texUnit(shader.ID, "tex0", 0);

    Crosshair crosshair("../assets/gui/crosshairs.png",width,height);

    while (!glfwWindowShouldClose(window)) {
        float currentFrame = glfwGetTime();
        float dt = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glClearColor(0.25f,0.5f,0.75f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.use();
        dirtTex.Bind();
        

        player.update(window, dt, world);
        camera.Matrix(45.0f, 0.1f, 100.0f, shader, "camMatrix");
        camera.Inputs(window);

        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f));
        shader.setMat4("model", model);
        world.draw(shader);
        crosshair.Draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    dirtTex.Delete();
    shader.Delete();
    glfwTerminate();
    return 0;
}
