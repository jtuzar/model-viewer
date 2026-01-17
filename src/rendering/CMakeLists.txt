add_library(rendering STATIC)

mv_enable_debug_macro(rendering)

target_include_directories(rendering PUBLIC "${PROJECT_SOURCE_DIR}/src")

target_sources(rendering
  PRIVATE
    vertex_array.cpp
    vertex_buffer.cpp
    shader_program.cpp
    opengl_context.cpp
    model.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS "${PROJECT_SOURCE_DIR}/src"
    FILES
      "${CMAKE_CURRENT_SOURCE_DIR}/vertex_array.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/vertex_buffer.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/shader_program.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/opengl_context.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/model.hpp"
)

target_link_libraries(rendering PRIVATE glad math assets)


