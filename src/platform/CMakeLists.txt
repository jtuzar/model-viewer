add_library(platform STATIC)

mv_enable_debug_macro(platform)

target_include_directories(platform PUBLIC "${PROJECT_SOURCE_DIR}/src")

target_sources(platform
  PRIVATE
    window.cpp
    window_context.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS "${PROJECT_SOURCE_DIR}/src"
    FILES
      "${CMAKE_CURRENT_SOURCE_DIR}/window.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/window_context.hpp"
)

target_link_libraries(platform glfw glad)


