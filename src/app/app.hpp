#pragma once

#include "platform/window.hpp"
#include "platform/window_context.hpp"
#include "rendering/opengl_context.hpp"
#include "rendering/renderer.hpp"
class App {
   public:
    explicit App(const char* appName,
                 unsigned int windowWidth = 1920,
                 unsigned int windowHeight = 1080);
    void run();

   private:
    WindowContext windowContext_;
    Window window_;
    OpenGlContext glContext_;
    Renderer renderer_;
};
