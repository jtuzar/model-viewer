add_library(rendering STATIC)

mv_enable_debug_macro(rendering)

target_include_directories(rendering
  PUBLIC "${PROJECT_SOURCE_DIR}/src"
  PRIVATE "${PROJECT_SOURCE_DIR}/src/internal")

target_sources(rendering
  PRIVATE
    vertex_array.cpp
    shader_program.cpp
    opengl_context.cpp
    model.cpp
    renderer.cpp
    internal/gl_buffer.hpp
    internal/gl_buffer.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS "${PROJECT_SOURCE_DIR}/src"
    FILES
      "${CMAKE_CURRENT_SOURCE_DIR}/vertex_array.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/shader_program.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/opengl_context.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/model.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/renderer.hpp"
)

target_link_libraries(rendering PRIVATE glad math assets)


