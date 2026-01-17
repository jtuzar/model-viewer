add_library(assets STATIC)

mv_enable_debug_macro(assets)

set_target_properties(assets PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(assets PUBLIC "${PROJECT_SOURCE_DIR}/src")

target_sources(assets
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS "${PROJECT_SOURCE_DIR}/src"
    FILES
      "${CMAKE_CURRENT_SOURCE_DIR}/mesh.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/vertex.hpp"
)

target_link_libraries(assets PRIVATE math)

