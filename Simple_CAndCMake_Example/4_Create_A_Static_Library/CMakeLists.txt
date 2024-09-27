cmake_minimum_required(VERSION 3.30.3)
# Sets the minimum required CMake version for this project.

project(directory_test)
# Defines the project name.

# new command setup builder
set(CMAKE_BUILD_TYPE Release)
# Sets the build type to "Release" for optimized builds.

include_directories(include)
# Adds the "include" directory to the search path for header files.

file(GLOB SOURCES "src/*.cpp")
# Finds all C++ source files in the "src" directory.

# new command to add lib
add_library(testStudent STATIC ${SOURCES})
# Creates a static library named "testStudent" using the same source files.

# new command to install in destination
install(TARGETS testStudent DESTINATION ./usr/lib)
# Installs the "testStudent" target (both executable and shared library) to the specified destination.