#pragma once

#include <GLFW/glfw3.h>
class WindowContext {
   public:
    WindowContext();
    ~WindowContext();

    WindowContext(const WindowContext&) = delete;
    WindowContext& operator=(const WindowContext&) = delete;
    WindowContext(const WindowContext&&) = delete;
    WindowContext& operator=(const WindowContext&&) = delete;

    void pollEvents() const;

   private:
    inline static bool isInitialized_ = false;
};
