add_executable(minimal_square
    main.cpp
)

target_include_directories(minimal_square PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(minimal_square
    PRIVATE
        Claymore::core
        Claymore::layout_computers
        Claymore::renderers
        Claymore::displays
        Claymore::views
        raylib
        clay
)

set_target_properties(minimal_square PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CLAYMORE_BUILD_MODE}"
)