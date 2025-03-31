add_library(claymore_views STATIC
    ViewMinimal.cpp
)

target_include_directories(claymore_views PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(claymore_views
    PRIVATE clay
)

add_library(Claymore::views ALIAS claymore_views)
