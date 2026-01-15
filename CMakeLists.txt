cmake_minimum_required(VERSION 3.20)

project(model-viewer)

function(mv_enable_debug_macro target)
  target_compile_definitions(${target}
        PRIVATE
            $<$<CONFIG:Debug>:MV_DEBUG=1>
    )
endfunction()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(third_party)
add_subdirectory(src/platform)

add_executable(model-viewer
  src/main.cpp
  src/shader.cpp
)
target_include_directories(model-viewer PRIVATE src)
target_link_libraries(model-viewer PRIVATE platform)

mv_enable_debug_macro(model-viewer)


set(SHADERS_SRC_DIR "${CMAKE_SOURCE_DIR}/shaders")
set(SHADERS_DST_DIR "$<TARGET_FILE_DIR:model-viewer>/shaders")

add_custom_command(
    TARGET model-viewer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${SHADERS_DST_DIR}"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${SHADERS_SRC_DIR}" "${SHADERS_DST_DIR}"
    COMMENT "Copying shaders to runtime output directory"
)
