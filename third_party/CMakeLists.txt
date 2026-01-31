include(FetchContent)

FetchContent_Declare(
glfw
GIT_REPOSITORY https://github.com/glfw/glfw
GIT_TAG 7b6aead9fb88b3623e3b3725ebb42670cbe4c579 #3.4
)
FetchContent_MakeAvailable(glfw)

if(MV_BUILD_TESTS)
  FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.4
  )
  FetchContent_MakeAvailable(Catch2)
endif()

add_subdirectory(glad)
