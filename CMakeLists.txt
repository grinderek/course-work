cmake_minimum_required(VERSION 3.20)
project(course_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(course_test main.cpp User.cpp User.h Service.h Service.cpp CRUD.h CRUD.cpp groups_service.h tests_service.h tests_service.cpp tables_service.h Question_Many_Variants.cpp Question_Many_Variants.h tables_service.cpp questions_service.h questions_service.cpp SqlGateway.cpp SqlGateway.h Test.cpp Test.h groups_service.cpp)
target_link_libraries(course_test -lsqlite3)
