#include "platform/window.hpp"
#include <GLFW/glfw3.h>
#include <stdexcept>

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
}

Window::~Window() {
    if (glfwWindow_ != nullptr) {
        glfwDestroyWindow(glfwWindow_);
        glfwWindow_ = nullptr;
    }
}

void Window::swapBuffers() const {
    glfwSwapBuffers(glfwWindow_);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(glfwWindow_);
}

void Window::makeContextCurrent() const {
    glfwMakeContextCurrent(glfwWindow_);
}

GLProcLoader Window::getGLProcLoader() const {
    return glfwGetProcAddress;
}
