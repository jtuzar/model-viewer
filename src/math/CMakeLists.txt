add_library(math STATIC)

mv_enable_debug_macro(math)

set_target_properties(math PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(math PUBLIC "${PROJECT_SOURCE_DIR}/src")

target_sources(math
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS "${PROJECT_SOURCE_DIR}/src"
    FILES
      "${CMAKE_CURRENT_SOURCE_DIR}/vec2.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/vec3.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/vec4.hpp"
)

if(MV_BUILD_TESTS)
  add_subdirectory(tests)
endif()
