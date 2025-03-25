cmake_minimum_required(VERSION 3.20)
project(Claymore LANGUAGES CXX)

# Set default C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Optionally set build type if not set
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Include Clay UI
set(CLAY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/clay)

# Add Clay UI + Raylib (assumes Git submodules)
add_subdirectory(external/clay)
add_subdirectory(external/raylib)

# Include directories (public API)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source folders
add_subdirectory(src/core)
add_subdirectory(src/layout)
add_subdirectory(src/renderer_adapter)
add_subdirectory(src/themes)
add_subdirectory(src/ui/components)
add_subdirectory(src/ui/views)

# Optionally: examples, tools, tests
add_subdirectory(examples)
add_subdirectory(tools)
add_subdirectory(tests)

add_library(claymore STATIC "")
target_link_libraries(claymore
    claymore_core
    claymore_layout
    # claymore_themes
    # claymore_renderer_adapter
    # claymore_ui_components
    # claymore_ui_views
)

target_include_directories(claymore_core PUBLIC ${CMAKE_SOURCE_DIR}/external/clay)