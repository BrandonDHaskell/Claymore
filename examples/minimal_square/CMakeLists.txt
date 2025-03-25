cmake_minimum_required(VERSION 3.27)

project(minimal_square_example)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(minimal_square
    main.cpp
)

target_include_directories(minimal_square PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(minimal_square
    # claymore_core
    # claymore_layout
    # claymore_renderer_adapter
    # clay
    raylib
)