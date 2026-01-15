#include <glad/gl.h>
#include "window.hpp"
#include <stdexcept>

#if MV_DEBUG
#include <iostream>
void enableGlDebug();
#endif

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

    enableGlDebug();
#endif
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

#if MV_DEBUG
static void APIENTRY glDebugCallback(GLenum source,
                                     GLenum type,
                                     GLuint id,
                                     GLenum severity,
                                     GLsizei length,
                                     const GLchar* message,
                                     const void* userParam) {
    std::fprintf(stderr, "GL DEBUG: %s\n", message);
}

void enableGlDebug() {
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(glDebugCallback, nullptr);

    int flags = 0;
    glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
    if (flags & GL_CONTEXT_FLAG_DEBUG_BIT) {
        std::printf("Debug context: YES\n");
    } else {
        std::printf("Debug context: NO\n");
    }
}
#endif
