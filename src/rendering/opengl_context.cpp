#include "platform/window.hpp"
#include "rendering/opengl_context.hpp"
#include <iostream>
#include <glad/gl.h>
#include <stdexcept>

#if MV_DEBUG
#include <iostream>
void enableGlDebug();
#endif

OpenGlContext::OpenGlContext(Window& window) {
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
void glDebugCallback(unsigned int source,
                     unsigned int type,
                     unsigned int id,
                     unsigned int severity,
                     int length,
                     const char* message,
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
