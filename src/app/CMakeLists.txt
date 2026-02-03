add_library(app STATIC)

mv_enable_debug_macro(app)

target_include_directories(app PUBLIC "${PROJECT_SOURCE_DIR}/src")

target_sources(
    app
    PRIVATE app.cpp scene.cpp
    PUBLIC
        FILE_SET HEADERS
            BASE_DIRS "${PROJECT_SOURCE_DIR}/src"
            FILES
                "${CMAKE_CURRENT_SOURCE_DIR}/app.hpp"
                "${CMAKE_CURRENT_SOURCE_DIR}/scene.hpp"
)

target_link_libraries(app PRIVATE platform rendering math assets)
