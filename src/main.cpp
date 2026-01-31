#include "rendering/renderer.hpp"
#include "rendering/opengl_context.hpp"
#include "platform/window_context.hpp"
#include "platform/window.hpp"
#include "rendering/shader_program.hpp"

static const Mesh testMesh = Mesh{
    .vertices{
        // +Z (front)
        {{-0.5f, -0.5f, 0.5f}, {0, 0, 1}, {0, 0}},
        {{0.5f, -0.5f, 0.5f}, {0, 0, 1}, {1, 0}},
        {{0.5f, 0.5f, 0.5f}, {0, 0, 1}, {1, 1}},
        {{0.5f, 0.5f, 0.5f}, {0, 0, 1}, {1, 1}},
        {{-0.5f, 0.5f, 0.5f}, {0, 0, 1}, {0, 1}},
        {{-0.5f, -0.5f, 0.5f}, {0, 0, 1}, {0, 0}},

        // -Z (back)
        {{0.5f, -0.5f, -0.5f}, {0, 0, -1}, {0, 0}},
        {{-0.5f, -0.5f, -0.5f}, {0, 0, -1}, {1, 0}},
        {{-0.5f, 0.5f, -0.5f}, {0, 0, -1}, {1, 1}},
        {{-0.5f, 0.5f, -0.5f}, {0, 0, -1}, {1, 1}},
        {{0.5f, 0.5f, -0.5f}, {0, 0, -1}, {0, 1}},
        {{0.5f, -0.5f, -0.5f}, {0, 0, -1}, {0, 0}},

        // -X (left)
        {{-0.5f, -0.5f, -0.5f}, {-1, 0, 0}, {0, 0}},
        {{-0.5f, -0.5f, 0.5f}, {-1, 0, 0}, {1, 0}},
        {{-0.5f, 0.5f, 0.5f}, {-1, 0, 0}, {1, 1}},
        {{-0.5f, 0.5f, 0.5f}, {-1, 0, 0}, {1, 1}},
        {{-0.5f, 0.5f, -0.5f}, {-1, 0, 0}, {0, 1}},
        {{-0.5f, -0.5f, -0.5f}, {-1, 0, 0}, {0, 0}},

        // +X (right)
        {{0.5f, -0.5f, 0.5f}, {1, 0, 0}, {0, 0}},
        {{0.5f, -0.5f, -0.5f}, {1, 0, 0}, {1, 0}},
        {{0.5f, 0.5f, -0.5f}, {1, 0, 0}, {1, 1}},
        {{0.5f, 0.5f, -0.5f}, {1, 0, 0}, {1, 1}},
        {{0.5f, 0.5f, 0.5f}, {1, 0, 0}, {0, 1}},
        {{0.5f, -0.5f, 0.5f}, {1, 0, 0}, {0, 0}},

        // -Y (bottom)
        {{-0.5f, -0.5f, -0.5f}, {0, -1, 0}, {0, 0}},
        {{0.5f, -0.5f, -0.5f}, {0, -1, 0}, {1, 0}},
        {{0.5f, -0.5f, 0.5f}, {0, -1, 0}, {1, 1}},
        {{0.5f, -0.5f, 0.5f}, {0, -1, 0}, {1, 1}},
        {{-0.5f, -0.5f, 0.5f}, {0, -1, 0}, {0, 1}},
        {{-0.5f, -0.5f, -0.5f}, {0, -1, 0}, {0, 0}},

        // +Y (top)
        {{-0.5f, 0.5f, 0.5f}, {0, 1, 0}, {0, 0}},
        {{0.5f, 0.5f, 0.5f}, {0, 1, 0}, {1, 0}},
        {{0.5f, 0.5f, -0.5f}, {0, 1, 0}, {1, 1}},
        {{0.5f, 0.5f, -0.5f}, {0, 1, 0}, {1, 1}},
        {{-0.5f, 0.5f, -0.5f}, {0, 1, 0}, {0, 1}},
        {{-0.5f, 0.5f, 0.5f}, {0, 1, 0}, {0, 0}},
    },
};

int main() {
    WindowContext windowContext;
    Window window{1920, 1080, "model-viewer", windowContext};
    OpenGlContext glContext{window};

    Renderer renderer{glContext};
    ShaderProgram shaderProgram{"shaders/default.vert", "shaders/default.frag"};
    renderer.submit(testMesh, &shaderProgram);

    while (!window.shouldClose()) {
        renderer.draw();

        window.swapBuffers();
        windowContext.pollEvents();
    }

    return 0;
}
