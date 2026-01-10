cmake_minimum_required(VERSION 4.2.1)
cmake_policy(VERSION 4.2.1)

project(model-viewer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
glfw
GIT_REPOSITORY https://github.com/glfw/glfw
GIT_TAG 7b6aead9fb88b3623e3b3725ebb42670cbe4c579 #3.4
)
FetchContent_MakeAvailable(glfw)

add_executable(model-viewer src/main.cpp src/gl.c)
target_link_libraries(model-viewer glfw)
target_include_directories(model-viewer PRIVATE includes)
