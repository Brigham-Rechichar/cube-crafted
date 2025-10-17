#pragma once

#include <string>
#include <iostream>
#include <GLFW/glfw3.h>

class Window{

private:
    int widith;
    int height;
    std::string title;
    GLFWwindow* window;

public:

//constructor and deconstructor

    Window(int w,int h,std::string);
    ~Window();

//core functions

    bool init(); //creating the window
    void update(); //
    void close(); //closing the window
    bool shouldClose(); // checking if the window should be closed

//getters

    //using inline for linker errors
    inline int getWidith() const {return widith;}
    inline int getHeight() const {return height;}
    //const is used here for 
    inline GLFWwindow* getNativeWindow() const {return window;}
};