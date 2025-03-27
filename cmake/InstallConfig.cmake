include(CMakePackageConfigHelpers)

# Install Targets
install(TARGETS
    claymore_layout
    claymore_renderer
    clay
    EXPORT ClaymoreTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
        DESTINATION include)

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

install(EXPORT ClaymoreTargets
        FILE ClaymoreTargets.cmake
        NAMESPACE Claymore::
        DESTINATION lib/cmake/Claymore)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/ClaymoreConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/ClaymoreConfigVersion.cmake"
    DESTINATION lib/cmake/Claymore)
