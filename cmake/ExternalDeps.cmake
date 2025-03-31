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
        add_library(raylib STATIC IMPORTED GLOBAL)
        set_target_properties(raylib PROPERTIES
            IMPORTED_LOCATION "${CLAYMORE_RAYLIB_PATH}/lib/libraylib.a"
            INTERFACE_INCLUDE_DIRECTORIES "${CLAYMORE_RAYLIB_PATH}/include"
        )
    else()
        message(FATAL_ERROR "CLAYMORE_RAYLIB_PATH must be set when CLAMORE_ENABLE_EXTERNALS is OFF.")
    endif()
    # find_package(raylib REQUIRED)
endif()
