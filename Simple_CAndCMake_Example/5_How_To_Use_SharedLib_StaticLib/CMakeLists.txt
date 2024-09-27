cmake_minimum_required(VERSION 3.30.3)
project (TestLibrary)

# For the shared library:
set(PROJECT_LINK_LIBS libtestStudent.so)
link_directories(../3_Create_A_Shared_Library/build)
#link_directories(/home/harito/Documents/Tutorial_C/Simple_CAndCMake_Example/3_Create_A_Shared_Library/build)

# For the static library:
#set (PROJECT_LINK_LIBS libtestStudent.a)
#link_directories(../../4*Static*/build)

#include_directories(../../3*Shared*/include)
include_directories(../3_Create_A_Shared_Library/include)
#include_directories(../../4*Static*/include)

add_executable(libtest libtest.cpp)
target_link_libraries(libtest ${PROJECT_LINK_LIBS})
