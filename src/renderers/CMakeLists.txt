add_library(claymore_renderers STATIC
    RendererRaylib.cpp
)

target_include_directories(claymore_renderers PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(claymore_renderers
    PRIVATE raylib
)

add_library(Claymore::renderers ALIAS claymore_renderers)
