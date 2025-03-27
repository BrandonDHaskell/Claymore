cmake_minimum_required(VERSION 3.28)
project(Claymore LANGUAGES CXX)

# Set default C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(CLAYMORE_ENABLE_EXTERNALS "Use Git submodules for Clay/Raylib" OFF)
option(CLAYMORE_RAYLIB_PATH "Path to installed Raylib" "")

# Optionally set build type if not set
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# -----------------------------------------
# Internal header-only Clay dependency
# -----------------------------------------
add_library(clay INTERFACE)

target_include_directories(clay INTERFACE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/external/clay>
    $<INSTALL_INTERFACE:include/clay>
)

# Install the clay.h header(s)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/external/clay/
        DESTINATION include/clay)

# Raylib is optional: use installed or submodule
if(CLAYMORE_ENABLE_EXTERNALS)
    add_subdirectory(external/raylib)
else()
    if(CLAYMORE_RAYLIB_PATH)
        list(APPEND CMAKE_PREFIX_PATH "${CLAYMORE_RAYLIB_PATH}")
    endif()
    find_package(raylib REQUIRED)
endif()

# Include directories (public API)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source folders
# add_subdirectory(src/core)
add_subdirectory(src/layout)
add_library(Claymore::claymore_layout ALIAS claymore_layout)
# add_subdirectory(src/renderer_adapter)
# add_subdirectory(src/themes)
# add_subdirectory(src/ui/components)
# add_subdirectory(src/ui/views)

# Optionally: examples, tools, tests
add_subdirectory(examples/minimal_square)
# add_subdirectory(tools)
# add_subdirectory(tests)

add_library(claymore INTERFACE)
target_link_libraries(claymore INTERFACE
    # claymore_core
    Claymore::claymore_layout
    # claymore_themes
    # claymore_renderer_adapter
    # claymore_ui_components
    # claymore_ui_views
    # if(TARGET raylib)
    #   target_link_libraries(claymore PRIVATE raylib)
    # endif()
)

# -------------------------------
# Claymore Export + Install Setup
# -------------------------------

include(CMakePackageConfigHelpers)

# Define an export group
install(TARGETS
    claymore_layout
    clay
    # TODO: Add other targets later
    # claymore_renderer_adapter
    # claymore_themes
    # claymore_ui_components
    # claymore_ui_views
    EXPORT ClaymoreTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# Install public headers
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
        DESTINATION include)

# Generate the config file
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/ClaymoreConfigVersion.cmake"
    VERSION 0.5.0
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    "${CMAKE_SOURCE_DIR}/cmake/ClaymoreConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/ClaymoreConfig.cmake"
    INSTALL_DESTINATION lib/cmake/Claymore
)

# Install the export config
install(EXPORT ClaymoreTargets
        FILE ClaymoreTargets.cmake
        NAMESPACE Claymore::
        DESTINATION lib/cmake/Claymore)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/ClaymoreConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/ClaymoreConfigVersion.cmake"
    DESTINATION lib/cmake/Claymore)
