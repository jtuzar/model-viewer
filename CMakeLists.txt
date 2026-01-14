cmake_minimum_required(VERSION 4.2.1)
cmake_policy(VERSION 4.2.1)

project(model-viewer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(third_party)
add_subdirectory(src/platform)

add_executable(model-viewer src/main.cpp src/shader.cpp)
target_link_libraries(model-viewer platform)
target_include_directories(model-viewer PRIVATE src)

add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders
        ${CMAKE_BINARY_DIR}/shaders

    COMMENT "Copying assets to build directory"
)
