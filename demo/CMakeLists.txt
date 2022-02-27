# Minimum CMake version required
cmake_minimum_required(VERSION 3.13.0)

# Project (also works w/o version)
project(My_Project VERSION 1.0.0)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# =================================
# Targets
# =================================

add_executable(demo demo.cpp)
target_link_libraries( demo PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../build/libmathLib.dylib )
   # ${CMAKE_CURRENT_SOURCE_DIR}/../build/libaddNumbers.a )
target_include_directories(demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../)