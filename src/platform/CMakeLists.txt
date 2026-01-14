add_library(platform)

target_sources(platform
  PRIVATE
    window.cpp
  PUBLIC
    FILE_SET HEADERS
    FILES
      window.hpp
)


