cmake_minimum_required(VERSION 3.28)
project(Claymore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include modular CMake configs
include(cmake/CompilerSettings.cmake)
include(cmake/ExternalDeps.cmake)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src/layout)
add_library(Claymore::claymore_layout ALIAS claymore_layout)

add_subdirectory(src/renderer)
add_library(Claymore::claymore_renderer ALIAS claymore_renderer)

add_library(claymore INTERFACE)
target_link_libraries(claymore INTERFACE
    Claymore::claymore_layout
    Claymore::claymore_renderer
)

add_subdirectory(examples/minimal_square)

include(cmake/InstallConfig.cmake)
