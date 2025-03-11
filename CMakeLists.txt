cmake_minimum_required(VERSION 3.31)

project(VapoR LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)

include(GNUInstallDirs)

add_subdirectory(src)

install(DIRECTORY data/ DESTINATION ${CMAKE_INSTALL_DATADIR}/VapoR)

configure_file(openvrpaths.vrpath.in openvrpaths.vrpath)
install(FILES ${CMAKE_BINARY_DIR}/openvrpaths.vrpath DESTINATION ${CMAKE_INSTALL_LIBDIR}/VapoR)
