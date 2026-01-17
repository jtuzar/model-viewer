add_library(rendering STATIC)

mv_enable_debug_macro(rendering)

target_include_directories(rendering PUBLIC "${PROJECT_SOURCE_DIR}/src")

target_sources(rendering
  PRIVATE
    opengl/vertex_array.cpp
    opengl/vertex_buffer.cpp
    opengl/shader.cpp
    opengl/renderer_opengl.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS "${PROJECT_SOURCE_DIR}/src"
    FILES
      "${CMAKE_CURRENT_SOURCE_DIR}/opengl/vertex_array.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/opengl/vertex_buffer.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/opengl/shader.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/opengl/renderer_opengl.hpp"
)

target_link_libraries(rendering PRIVATE glad math assets)


