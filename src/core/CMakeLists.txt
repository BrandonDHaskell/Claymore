# Define Claymore core engine as a static library
add_library(claymore_core STATIC
    ClaymoreEngine.cpp
)

# Include core headers
target_include_directories(claymore_core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Link with Claymore interfaces and render command structs
target_link_libraries(claymore_core
    PRIVATE
        Claymore::layout_computers
        Claymore::renderers
        Claymore::displays
        Claymore::views
)

add_library(Claymore::core ALIAS claymore_core)
