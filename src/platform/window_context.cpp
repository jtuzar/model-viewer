#include <glad/gl.h>
#include "window_context.hpp"
#include <GLFW/glfw3.h>
#include <cassert>
#include <stdexcept>

WindowContext::WindowContext() {
    if (isInitialized_)
        throw std::runtime_error("Cannot initialize GLFW twice");

    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

    isInitialized_ = true;
}

WindowContext::~WindowContext() {
    if (isInitialized_) {
        glfwTerminate();
        isInitialized_ = false;
    }
}

void WindowContext::pollEvents() const {
    glfwPollEvents();
}
