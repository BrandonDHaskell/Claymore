# include/claymore/renderer/CMakeLists.txt

add_library(claymore_renderer STATIC
    raylib_renderer.cpp
)

target_include_directories(claymore_renderer PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(claymore_renderer PRIVATE
    raylib
)

add_library(Claymore::claymore_renderer ALIAS claymore_renderer)
