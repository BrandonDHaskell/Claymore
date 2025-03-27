# src/layout/CMakeLists.txt

add_library(claymore_layout STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/clay_layout_computer.cpp
)

target_include_directories(claymore_layout PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(claymore_layout PUBLIC clay)

