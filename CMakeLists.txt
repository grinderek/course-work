cmake_minimum_required(VERSION 3.20)
project(course_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(course_test main.cpp User.cpp User.h Service.h Service.cpp Authorization.h Authorization.cpp GroupInterface.h TestInterface.h TestInterface.cpp Question.cpp Question.h SqlGateway.cpp SqlGateway.h Test.cpp Test.h GroupInterface.cpp Group.cpp Group.h TestingInterface.h TestingInterface.cpp Answer.cpp Answer.h JustInt.cpp JustInt.h Student.cpp Student.h Teacher.cpp Teacher.h Guest.cpp Guest.h Interface.cpp Interface.h)
target_link_libraries(course_test -lsqlite3)
