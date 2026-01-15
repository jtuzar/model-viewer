add_library(rendering STATIC)

mv_enable_debug_macro(rendering)

target_sources(rendering
  PRIVATE
    vertex_array.cpp
    vertex_buffer.cpp
  PUBLIC
    FILE_SET HEADERS
    FILES
      vertex_array.hpp
      vertex_buffer.hpp
)

target_link_libraries(rendering glad)


