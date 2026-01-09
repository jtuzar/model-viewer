cmake_minimum_required(VERSION 4.2.1)
cmake_policy(VERSION 4.2.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(model-viewer)
add_executable(model-viewer src/main.cpp src/test.cpp)
target_include_directories(model-viewer PRIVATE includes)
