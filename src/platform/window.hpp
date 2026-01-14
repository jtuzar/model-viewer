#pragma once
#define WINDOW_H

#include "GLFW/glfw3.h"

class Window {
   public:
    Window(unsigned int width,
           unsigned int height,
           const char* title,
           GLFWmonitor* monitor,
           GLFWwindow* share);
    ~Window();
    GLFWwindow* getGLFWHandle() const { return glfwWindow_; };

   private:
    GLFWwindow* glfwWindow_;
};
