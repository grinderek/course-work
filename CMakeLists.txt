cmake_minimum_required(VERSION 3.20)
project(course_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(course_test main.cpp User.cpp User.h Service.h Service.cpp CRUD.h CRUD.cpp)
target_link_libraries(course_test -lsqlite3)
