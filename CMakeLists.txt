cmake_minimum_required(VERSION 3.20)
project(Claymore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include modular CMake configs
include(cmake/CompilerSettings.cmake)
include(cmake/ExternalDeps.cmake)

# Subdirectories
add_subdirectory(src/layout_computers)
add_subdirectory(src/renderers)
add_subdirectory(src/displays)
add_subdirectory(src/views)
add_subdirectory(src/core)
add_subdirectory(examples/minimal_square)

include(cmake/InstallConfig.cmake)

# Interface target to group components
add_library(Claymore INTERFACE)
target_link_libraries(Claymore INTERFACE
    Claymore::layout_computers
    Claymore::renderers
    Claymore::displays
    Claymore::views
)

add_library(Claymore::claymore INTERFACE IMPORTED GLOBAL)
set_target_properties(Claymore::claymore PROPERTIES
    INTERFACE_LINK_LIBRARIES "Claymore::claymore_core;Claymore::claymore_layout_computers;Claymore::claymore_renderers;Claymore::claymore_displays;Claymore::claymore_views"
)