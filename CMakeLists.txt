# Minimum CMake version required
cmake_minimum_required(VERSION 3.13.0)

# Project (also works w/o version)
project(My_Project VERSION 1.0.0)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
option(STATIC_BUNDLED "Combined static library" ON)

if (NOT STATIC_BUNDLED)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

# =============================
# Targets 
# =============================
add_library( addNumbers addNumbers.cpp)

if ( STATIC_BUNDLED )
    add_library( mathLib mathLib.cpp )
else()
    add_library( mathLib SHARED mathLib.cpp )
endif()
target_link_libraries( mathLib PRIVATE addNumbers)

## Bundle static libraries
if (STATIC_BUNDLED)
    set(CMAKE_CXX_COMPILER_ID "Clang")
    include( cmake/bundleStaticLibrary.cmake )
    bundle_static_library( mathLib mathLibBundled )

    set(INCLUDE_INSTALL_DIR include CACHE FILEPATH "" )
    set(LIB_INSTALL_DIR lib CACHE FILEPATH "" )
    set(PROJECT_NAME_LIB mathLibBundled CACHE FILEPATH "") 

    ## Installation
    include(CMakePackageConfigHelpers)
    configure_package_config_file(mathLib-config.cmake.in 
        ${CMAKE_CURRENT_BINARY_DIR}/mathLib-config.cmake 
        INSTALL_DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/mathLib
        PATH_VARS LIB_INSTALL_DIR INCLUDE_INSTALL_DIR )

    #install(TARGETS bundling_target EXPORT my_libExp DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
    #install(EXPORT my_libExp FILE mathLibBundled-config.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
endif()

# https://stackoverflow.com/questions/39103110/create-cmake-cpack-libraryconfig-cmake-for-shared-library
# https://www.f-ax.de/dev/2020/10/07/cmake-config-package.html
# https://stackoverflow.com/questions/49857596/cmake-simple-config-file-example
