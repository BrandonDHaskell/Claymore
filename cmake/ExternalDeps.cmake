# Clay (header-only)
add_library(clay INTERFACE)
target_include_directories(clay INTERFACE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/external/clay>
    $<INSTALL_INTERFACE:include/clay>
)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/external/clay/
        DESTINATION include/clay)

# Raylib (external or submodule)
if(CLAYMORE_ENABLE_EXTERNALS)
    add_subdirectory(external/raylib)
else()
    if(CLAYMORE_RAYLIB_PATH)
        list(APPEND CMAKE_PREFIX_PATH "${CLAYMORE_RAYLIB_PATH}")
    endif()
    find_package(raylib REQUIRED)
endif()
