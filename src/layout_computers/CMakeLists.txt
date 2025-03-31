add_library(claymore_layout_computers STATIC
    LayoutComputerClay.cpp
)

# Suppress compiler options for clay
target_compile_options(claymore_layout_computers PRIVATE
    -Wno-missing-field-initializers
    -Wno-old-style-cast
    -Wno-float-conversion
    -Wno-conversion
    -Wno-sign-compare
    -Wno-unknown-pragmas
)

target_include_directories(claymore_layout_computers PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(claymore_layout_computers
    PRIVATE clay
)

add_library(Claymore::layout_computers ALIAS claymore_layout_computers)