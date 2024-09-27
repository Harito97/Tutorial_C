cmake_minimum_required(VERSION 3.30.3)
# current newest cmake version of the system

project(directory_test)
# setup project name 
# - that will generate a new file with project name

include_directories(include)
# make project include header files (.h) in build env

#set(SOURCES src/mainapp.cpp src/Student.cpp)
# command to add src file to build env
# however we can make shorter by this command
file(GLOB SOURCES "src/*.cpp")

add_executable(testStudent ${SOURCES})
# sử dụng biến SOURCE 
# thay vì việc sử dụng tham chiếu cụ thể của từng source file 
# để build một chương trình executable là testStudent
