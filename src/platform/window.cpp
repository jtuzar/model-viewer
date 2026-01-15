#include <glad/gl.h>
#include "window.hpp"
#include <stdexcept>

#if MV_DEBUG
#include <iostream>
#endif  // !DEBUG

Window::Window(unsigned int width,
               unsigned int height,
               const char* title,
               GLFWmonitor* monitor,
               GLFWwindow* share,
               WindowContext& windowContext) {
    glfwWindow_ = glfwCreateWindow(width, height, title, monitor, share);

    if (!glfwWindow_) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(glfwWindow_);

    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0) {
        glfwDestroyWindow(glfwWindow_);
        glfwWindow_ = nullptr;
        throw std::runtime_error("Failed to initialize OpenGL context");
    }
#if MV_DEBUG
    std::cout << "Loaded OpenGL " << GLAD_VERSION_MAJOR(version) << "."
              << GLAD_VERSION_MINOR(version) << std::endl;
#endif  // DEBUG
}

Window::~Window() {
    glfwDestroyWindow(glfwWindow_);
}

void Window::swapBuffers() const {
    glfwSwapBuffers(glfwWindow_);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(glfwWindow_);
}
