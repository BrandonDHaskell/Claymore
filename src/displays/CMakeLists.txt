add_library(claymore_displays STATIC
    DisplayRaylib.cpp
)

target_include_directories(claymore_displays PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(claymore_displays
    PRIVATE raylib
)

add_library(Claymore::displays ALIAS claymore_displays)
