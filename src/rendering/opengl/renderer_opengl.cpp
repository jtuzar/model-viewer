#include "platform/window.hpp"
#include "rendering/opengl/renderer_opengl.hpp"
#include <iostream>
#include <glad/gl.h>
#include <stdexcept>

#if MV_DEBUG
#include <iostream>
void enableGlDebug();
#endif

RendererOpenGL::RendererOpenGL(Window& window) {
    window.makeContextCurrent();
    int version = gladLoadGL(window.getGLProcLoader());
    if (version == 0) {
        throw std::runtime_error("Failed to initialize OpenGL context");
    }
#if MV_DEBUG
    std::cout << "Loaded OpenGL " << GLAD_VERSION_MAJOR(version) << "."
              << GLAD_VERSION_MINOR(version) << std::endl;

    enableGlDebug();
#endif
}

#if MV_DEBUG
void glDebugCallback(GLenum source,
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
