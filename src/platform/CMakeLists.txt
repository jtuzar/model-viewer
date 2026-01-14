add_library(platform)

include(FetchContent)

FetchContent_Declare(
glfw
GIT_REPOSITORY https://github.com/glfw/glfw
GIT_TAG 7b6aead9fb88b3623e3b3725ebb42670cbe4c579 #3.4
)
FetchContent_MakeAvailable(glfw)

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


