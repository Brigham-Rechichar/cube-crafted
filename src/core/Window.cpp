/*
    this file is for the GLFW window
*/

#include "core\Window.h"

Window::Window(int w,int h,std::string t){
    widith=w;
    height=h;
    title=t;


}

bool Window::init(){

    if(!glfwInit()){
        std::cout<<"could not open window";
        return false;
    }

    window=glfwCreateWindow(widith,height,"title",NULL,NULL);
    return true;
}