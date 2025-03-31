# Set build mode (DEBUG, DEV, PROD)
set(CLAYMORE_BUILD_MODE "DEV" CACHE STRING "Build mode: PROD, DEV, DEBUG")
set_property(CACHE CLAYMORE_BUILD_MODE PROPERTY STRINGS PROD DEV DEBUG)

if(CLAYMORE_BUILD_MODE STREQUAL "DEBUG")
    message(STATUS "Claymore Build Mode: DEBUG")
    add_compile_definitions(CLAYMOR_DEBUG)
    add_compile_options(
        -g -O0
        -Wall -Wextra -Wshadow -Wpedantic -Wconversion
        -Wnon-virtual-dtor -Wold-style-cast -Wnull-dereference
        -fsanitize=address,undefined
    )
    add_link_options(-fsanitize=address,undefined)

elseif(CLAYMORE_BUILD_MODE STREQUAL "DEV")
    message(STATUS "Claymore Build Mode: DEV")
    add_compile_definitions(CLAYMORE_DEV)
    add_compile_options(
        -O2
        -Wall -Wextra -Wshadow -Wpedantic -Wconversion
        -Wnon-virtual-dtor -Wold-style-cast -Wnull-dereference
    )

elseif(CLAYMORE_BUILD_MODE STREQUAL "PROD")
    message(STATUS "Claymore Build Mode: PROD")
    add_compile_definitions(CALYMORE_PROD)
    add_compile_options(-O3 -Wall -Wextra)
endif()
