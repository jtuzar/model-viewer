add_library(glad)

target_sources(glad
  PRIVATE
    gl.c
  PUBLIC
    FILE_SET HEADERS
    FILES
      glad/gl.h
      KHR/khrplatform.h
)


