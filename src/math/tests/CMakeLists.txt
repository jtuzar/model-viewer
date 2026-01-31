add_executable(mv-math-tests
  test_vec.cpp
  test_dot.cpp
)

target_link_libraries(mv-math-tests
  PRIVATE
    Catch2::Catch2WithMain
    math
)

include(FetchContent)
FetchContent_GetProperties(Catch2)
list(APPEND CMAKE_MODULE_PATH "${Catch2_SOURCE_DIR}/extras")
include(Catch)
catch_discover_tests(mv-math-tests)
