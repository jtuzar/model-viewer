#include "rendering/renderer.hpp"
#include "rendering/opengl_context.hpp"
#include "platform/window_context.hpp"
#include "platform/window.hpp"
#include "rendering/shader_program.hpp"

static const Mesh testMesh =
    Mesh{.vertices{Vertex{.position{0.5f, 0.5f, 0.0f}}, Vertex{.position{0.5f, -0.5f, 0.0f}},
                   Vertex{.position{-0.5f, -0.5f, 0.0f}}, Vertex{.position{-0.5f, 0.5f, 0.0f}}},
         .indices{0, 1, 3, 1, 2, 3}};

int main() {
    WindowContext windowContext;
    Window window{1920, 1080, "model-viewer", windowContext};
    OpenGlContext glContext{window};

    Renderer renderer{glContext};
    renderer.submit(testMesh, ShaderProgram{"shaders/default.vert", "shaders/default.frag"});

    while (!window.shouldClose()) {
        renderer.draw();

        window.swapBuffers();
        windowContext.pollEvents();
    }

    return 0;
}
