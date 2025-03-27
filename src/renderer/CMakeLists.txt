add_library(claymore_renderer STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/raylib_renderer.cpp
)

target_include_directories(claymore_renderer PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(claymore_renderer PRIVATE
    raylib
)