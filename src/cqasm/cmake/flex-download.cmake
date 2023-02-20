cmake_minimum_required(VERSION 3.20)

project(flex-download NONE)

include(ExternalProject)
ExternalProject_Add(
    flex
    URL "https://github.com/westes/flex/releases/download/v${FLEX_VERSION_REQUIRED}/flex-${FLEX_VERSION_REQUIRED}.tar.gz"
    SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/flex-build"
    INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/flex-install"
    CONFIGURE_COMMAND ""
    BUILD_COMMAND     ""
    INSTALL_COMMAND   ""
    TEST_COMMAND      ""
)
