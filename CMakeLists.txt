cmake_minimum_required(VERSION 3.20)
project(Claymore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Subdirectories
add_subdirectory(src/layout_computers)
add_subdirectory(src/renderers)
add_subdirectory(src/displays)
add_subdirectory(src/views)
add_subdirectory(src/core)
# add_subdirectory(examples/minimal_square)
if(CLAY_INCLUDE_ALL_EXAMPLES)
    add_subdirectory(examples/minimal_square)
endif()

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

# Include modular CMake configs
include(cmake/CompilerSettings.cmake)
include(cmake/ExternalDeps.cmake)
include(cmake/options.cmake)
include(cmake/InstallConfig.cmake)
