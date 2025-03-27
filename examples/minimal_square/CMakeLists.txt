# include raylib
find_package(raylib REQUIRED)

add_executable(minimal_square main.cpp)

target_link_libraries(minimal_square PRIVATE
    Claymore::claymore_layout
    raylib
)