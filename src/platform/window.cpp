#include "window.hpp"
#include <iostream>

Window::Window(unsigned int width,
               unsigned int height,
               const char* title,
               GLFWmonitor* monitor,
               GLFWwindow* share) {
    if (!glfwInit()) {
        std::cout << "GLFW initialization error" << std::endl;
    }

    glfwWindow_ = glfwCreateWindow(640, 640, title, monitor, share);

    if (!glfwWindow_) {
        std::cout << "Failed to create glfw window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(glfwWindow_);
};

Window::~Window() {
    glfwTerminate();
}
