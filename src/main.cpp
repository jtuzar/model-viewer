#include "rendering/model.hpp"
#include "rendering/opengl_context.hpp"
#include "platform/window_context.hpp"
#include "platform/window.hpp"

int main() {
    WindowContext windowContext;
    Window window{1920, 1080, "model-viewer", nullptr, nullptr, windowContext};
    OpenGlContext glContext{window};

    Model model{glContext};

    while (!window.shouldClose()) {
        model.draw();

        window.swapBuffers();
        windowContext.pollEvents();
    }

    return 0;
}
