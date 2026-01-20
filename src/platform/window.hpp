#pragma once

#include "platform/window_context.hpp"

struct GLFWwindow;
struct GLFWmonitor;

using GLProc = void (*)();
using GLProcLoader = GLProc (*)(const char* name);

class Window {
  public:
    Window(unsigned int width, unsigned int height, const char* title,
           WindowContext& windowContext);

    ~Window();
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    void swapBuffers() const;
    bool shouldClose() const;
    void makeContextCurrent() const;
    GLProcLoader getGLProcLoader() const;

  private:
    GLFWwindow* glfwWindow_{nullptr};
};
