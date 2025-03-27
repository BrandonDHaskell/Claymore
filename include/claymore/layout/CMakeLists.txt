# Assuming Clay will be valid C
# Suppressing C++ copmiler checks for Clay only
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(claymore_layout PRIVATE -Wno-missing-field-initializers)
endif()

add_library(claymore_layout STATIC
    clay_adapter.cpp
)

target_include_directories(claymore_layout PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(claymore_layout PUBLIC clay)