add_library(glad STATIC)

mv_enable_debug_macro(glad)

target_sources(glad
  PRIVATE
    gl.c
  PUBLIC
    FILE_SET HEADERS
    FILES
      glad/gl.h
      KHR/khrplatform.h
)


