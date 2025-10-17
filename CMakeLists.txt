cmake_minimum_required(VERSION 3.10)
project(MineCraftClone)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(MineCraftClone
    src/main.cpp
    src/entities/triangle.cpp
    src/entities/block.cpp
    src/graphics/shader.cpp
    src/entities/camera.cpp
    src/glad.c
)

target_include_directories(MineCraftClone PRIVATE ${CMAKE_SOURCE_DIR}/dependencies)

target_link_libraries(MineCraftClone glfw OpenGL::GL)


