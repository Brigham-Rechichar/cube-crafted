cmake_minimum_required(VERSION 3.10)
project(MineCraftClone)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)
include(FetchContent)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.3.8
)
FetchContent_MakeAvailable(glfw)

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


