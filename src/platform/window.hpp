#pragma once

#include "window_context.hpp"
#include <GLFW/glfw3.h>

class Window {
   public:
    Window(unsigned int width,
           unsigned int height,
           const char* title,
           GLFWmonitor* monitor,
           GLFWwindow* share,
           WindowContext& windowContext);

    ~Window();
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    void swapBuffers() const;
    bool shouldClose() const;

   private:
    GLFWwindow* glfwWindow_;
};
