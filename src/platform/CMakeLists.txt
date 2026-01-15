add_library(platform STATIC)

mv_enable_debug_macro(platform)

target_sources(platform
  PRIVATE
    window.cpp
    window_context.cpp
  PUBLIC
    FILE_SET HEADERS
    FILES
      window.hpp
      window_context.hpp
)

target_link_libraries(platform glfw glad)


