# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/175/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/175/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/danila/CLionProjects/course_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/danila/CLionProjects/course_test/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/course_test.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/course_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/course_test.dir/flags.make

CMakeFiles/course_test.dir/main.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/course_test.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/main.cpp.o -c /home/danila/CLionProjects/course_test/main.cpp

CMakeFiles/course_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/main.cpp > CMakeFiles/course_test.dir/main.cpp.i

CMakeFiles/course_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/main.cpp -o CMakeFiles/course_test.dir/main.cpp.s

CMakeFiles/course_test.dir/User.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/User.cpp.o: ../User.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/course_test.dir/User.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/User.cpp.o -c /home/danila/CLionProjects/course_test/User.cpp

CMakeFiles/course_test.dir/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/User.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/User.cpp > CMakeFiles/course_test.dir/User.cpp.i

CMakeFiles/course_test.dir/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/User.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/User.cpp -o CMakeFiles/course_test.dir/User.cpp.s

CMakeFiles/course_test.dir/Service.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/Service.cpp.o: ../Service.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/course_test.dir/Service.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/Service.cpp.o -c /home/danila/CLionProjects/course_test/Service.cpp

CMakeFiles/course_test.dir/Service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/Service.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/Service.cpp > CMakeFiles/course_test.dir/Service.cpp.i

CMakeFiles/course_test.dir/Service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/Service.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/Service.cpp -o CMakeFiles/course_test.dir/Service.cpp.s

CMakeFiles/course_test.dir/CRUD.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/CRUD.cpp.o: ../CRUD.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/course_test.dir/CRUD.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/CRUD.cpp.o -c /home/danila/CLionProjects/course_test/CRUD.cpp

CMakeFiles/course_test.dir/CRUD.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/CRUD.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/CRUD.cpp > CMakeFiles/course_test.dir/CRUD.cpp.i

CMakeFiles/course_test.dir/CRUD.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/CRUD.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/CRUD.cpp -o CMakeFiles/course_test.dir/CRUD.cpp.s

CMakeFiles/course_test.dir/tests_service.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/tests_service.cpp.o: ../tests_service.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/course_test.dir/tests_service.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/tests_service.cpp.o -c /home/danila/CLionProjects/course_test/tests_service.cpp

CMakeFiles/course_test.dir/tests_service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/tests_service.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/tests_service.cpp > CMakeFiles/course_test.dir/tests_service.cpp.i

CMakeFiles/course_test.dir/tests_service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/tests_service.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/tests_service.cpp -o CMakeFiles/course_test.dir/tests_service.cpp.s

CMakeFiles/course_test.dir/Question_Many_Variants.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/Question_Many_Variants.cpp.o: ../Question_Many_Variants.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/course_test.dir/Question_Many_Variants.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/Question_Many_Variants.cpp.o -c /home/danila/CLionProjects/course_test/Question_Many_Variants.cpp

CMakeFiles/course_test.dir/Question_Many_Variants.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/Question_Many_Variants.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/Question_Many_Variants.cpp > CMakeFiles/course_test.dir/Question_Many_Variants.cpp.i

CMakeFiles/course_test.dir/Question_Many_Variants.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/Question_Many_Variants.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/Question_Many_Variants.cpp -o CMakeFiles/course_test.dir/Question_Many_Variants.cpp.s

CMakeFiles/course_test.dir/questions_service.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/questions_service.cpp.o: ../questions_service.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/course_test.dir/questions_service.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/questions_service.cpp.o -c /home/danila/CLionProjects/course_test/questions_service.cpp

CMakeFiles/course_test.dir/questions_service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/questions_service.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/questions_service.cpp > CMakeFiles/course_test.dir/questions_service.cpp.i

CMakeFiles/course_test.dir/questions_service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/questions_service.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/questions_service.cpp -o CMakeFiles/course_test.dir/questions_service.cpp.s

CMakeFiles/course_test.dir/SqlGateway.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/SqlGateway.cpp.o: ../SqlGateway.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/course_test.dir/SqlGateway.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/SqlGateway.cpp.o -c /home/danila/CLionProjects/course_test/SqlGateway.cpp

CMakeFiles/course_test.dir/SqlGateway.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/SqlGateway.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/SqlGateway.cpp > CMakeFiles/course_test.dir/SqlGateway.cpp.i

CMakeFiles/course_test.dir/SqlGateway.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/SqlGateway.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/SqlGateway.cpp -o CMakeFiles/course_test.dir/SqlGateway.cpp.s

CMakeFiles/course_test.dir/Test.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/Test.cpp.o: ../Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/course_test.dir/Test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/Test.cpp.o -c /home/danila/CLionProjects/course_test/Test.cpp

CMakeFiles/course_test.dir/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/Test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/Test.cpp > CMakeFiles/course_test.dir/Test.cpp.i

CMakeFiles/course_test.dir/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/Test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/Test.cpp -o CMakeFiles/course_test.dir/Test.cpp.s

CMakeFiles/course_test.dir/groups_service.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/groups_service.cpp.o: ../groups_service.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/course_test.dir/groups_service.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/groups_service.cpp.o -c /home/danila/CLionProjects/course_test/groups_service.cpp

CMakeFiles/course_test.dir/groups_service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/groups_service.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/groups_service.cpp > CMakeFiles/course_test.dir/groups_service.cpp.i

CMakeFiles/course_test.dir/groups_service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/groups_service.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/groups_service.cpp -o CMakeFiles/course_test.dir/groups_service.cpp.s

CMakeFiles/course_test.dir/Group.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/Group.cpp.o: ../Group.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/course_test.dir/Group.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/Group.cpp.o -c /home/danila/CLionProjects/course_test/Group.cpp

CMakeFiles/course_test.dir/Group.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/Group.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/Group.cpp > CMakeFiles/course_test.dir/Group.cpp.i

CMakeFiles/course_test.dir/Group.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/Group.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/Group.cpp -o CMakeFiles/course_test.dir/Group.cpp.s

CMakeFiles/course_test.dir/testing_service.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/testing_service.cpp.o: ../testing_service.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/course_test.dir/testing_service.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/testing_service.cpp.o -c /home/danila/CLionProjects/course_test/testing_service.cpp

CMakeFiles/course_test.dir/testing_service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/testing_service.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/testing_service.cpp > CMakeFiles/course_test.dir/testing_service.cpp.i

CMakeFiles/course_test.dir/testing_service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/testing_service.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/testing_service.cpp -o CMakeFiles/course_test.dir/testing_service.cpp.s

CMakeFiles/course_test.dir/Answer.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/Answer.cpp.o: ../Answer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/course_test.dir/Answer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/Answer.cpp.o -c /home/danila/CLionProjects/course_test/Answer.cpp

CMakeFiles/course_test.dir/Answer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/Answer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/Answer.cpp > CMakeFiles/course_test.dir/Answer.cpp.i

CMakeFiles/course_test.dir/Answer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/Answer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/Answer.cpp -o CMakeFiles/course_test.dir/Answer.cpp.s

CMakeFiles/course_test.dir/JustInt.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/JustInt.cpp.o: ../JustInt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/course_test.dir/JustInt.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/JustInt.cpp.o -c /home/danila/CLionProjects/course_test/JustInt.cpp

CMakeFiles/course_test.dir/JustInt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/JustInt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/JustInt.cpp > CMakeFiles/course_test.dir/JustInt.cpp.i

CMakeFiles/course_test.dir/JustInt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/JustInt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/JustInt.cpp -o CMakeFiles/course_test.dir/JustInt.cpp.s

CMakeFiles/course_test.dir/Student.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/Student.cpp.o: ../Student.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/course_test.dir/Student.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/Student.cpp.o -c /home/danila/CLionProjects/course_test/Student.cpp

CMakeFiles/course_test.dir/Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/Student.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/Student.cpp > CMakeFiles/course_test.dir/Student.cpp.i

CMakeFiles/course_test.dir/Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/Student.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/Student.cpp -o CMakeFiles/course_test.dir/Student.cpp.s

CMakeFiles/course_test.dir/Teacher.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/Teacher.cpp.o: ../Teacher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/course_test.dir/Teacher.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/Teacher.cpp.o -c /home/danila/CLionProjects/course_test/Teacher.cpp

CMakeFiles/course_test.dir/Teacher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/Teacher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/Teacher.cpp > CMakeFiles/course_test.dir/Teacher.cpp.i

CMakeFiles/course_test.dir/Teacher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/Teacher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/Teacher.cpp -o CMakeFiles/course_test.dir/Teacher.cpp.s

CMakeFiles/course_test.dir/App.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/App.cpp.o: ../App.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/course_test.dir/App.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/App.cpp.o -c /home/danila/CLionProjects/course_test/App.cpp

CMakeFiles/course_test.dir/App.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/App.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/App.cpp > CMakeFiles/course_test.dir/App.cpp.i

CMakeFiles/course_test.dir/App.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/App.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/App.cpp -o CMakeFiles/course_test.dir/App.cpp.s

CMakeFiles/course_test.dir/Guest.cpp.o: CMakeFiles/course_test.dir/flags.make
CMakeFiles/course_test.dir/Guest.cpp.o: ../Guest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/course_test.dir/Guest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/course_test.dir/Guest.cpp.o -c /home/danila/CLionProjects/course_test/Guest.cpp

CMakeFiles/course_test.dir/Guest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/course_test.dir/Guest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danila/CLionProjects/course_test/Guest.cpp > CMakeFiles/course_test.dir/Guest.cpp.i

CMakeFiles/course_test.dir/Guest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/course_test.dir/Guest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danila/CLionProjects/course_test/Guest.cpp -o CMakeFiles/course_test.dir/Guest.cpp.s

# Object files for target course_test
course_test_OBJECTS = \
"CMakeFiles/course_test.dir/main.cpp.o" \
"CMakeFiles/course_test.dir/User.cpp.o" \
"CMakeFiles/course_test.dir/Service.cpp.o" \
"CMakeFiles/course_test.dir/CRUD.cpp.o" \
"CMakeFiles/course_test.dir/tests_service.cpp.o" \
"CMakeFiles/course_test.dir/Question_Many_Variants.cpp.o" \
"CMakeFiles/course_test.dir/questions_service.cpp.o" \
"CMakeFiles/course_test.dir/SqlGateway.cpp.o" \
"CMakeFiles/course_test.dir/Test.cpp.o" \
"CMakeFiles/course_test.dir/groups_service.cpp.o" \
"CMakeFiles/course_test.dir/Group.cpp.o" \
"CMakeFiles/course_test.dir/testing_service.cpp.o" \
"CMakeFiles/course_test.dir/Answer.cpp.o" \
"CMakeFiles/course_test.dir/JustInt.cpp.o" \
"CMakeFiles/course_test.dir/Student.cpp.o" \
"CMakeFiles/course_test.dir/Teacher.cpp.o" \
"CMakeFiles/course_test.dir/App.cpp.o" \
"CMakeFiles/course_test.dir/Guest.cpp.o"

# External object files for target course_test
course_test_EXTERNAL_OBJECTS =

course_test: CMakeFiles/course_test.dir/main.cpp.o
course_test: CMakeFiles/course_test.dir/User.cpp.o
course_test: CMakeFiles/course_test.dir/Service.cpp.o
course_test: CMakeFiles/course_test.dir/CRUD.cpp.o
course_test: CMakeFiles/course_test.dir/tests_service.cpp.o
course_test: CMakeFiles/course_test.dir/Question_Many_Variants.cpp.o
course_test: CMakeFiles/course_test.dir/questions_service.cpp.o
course_test: CMakeFiles/course_test.dir/SqlGateway.cpp.o
course_test: CMakeFiles/course_test.dir/Test.cpp.o
course_test: CMakeFiles/course_test.dir/groups_service.cpp.o
course_test: CMakeFiles/course_test.dir/Group.cpp.o
course_test: CMakeFiles/course_test.dir/testing_service.cpp.o
course_test: CMakeFiles/course_test.dir/Answer.cpp.o
course_test: CMakeFiles/course_test.dir/JustInt.cpp.o
course_test: CMakeFiles/course_test.dir/Student.cpp.o
course_test: CMakeFiles/course_test.dir/Teacher.cpp.o
course_test: CMakeFiles/course_test.dir/App.cpp.o
course_test: CMakeFiles/course_test.dir/Guest.cpp.o
course_test: CMakeFiles/course_test.dir/build.make
course_test: CMakeFiles/course_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable course_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/course_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/course_test.dir/build: course_test
.PHONY : CMakeFiles/course_test.dir/build

CMakeFiles/course_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/course_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/course_test.dir/clean

CMakeFiles/course_test.dir/depend:
	cd /home/danila/CLionProjects/course_test/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danila/CLionProjects/course_test /home/danila/CLionProjects/course_test /home/danila/CLionProjects/course_test/cmake-build-debug /home/danila/CLionProjects/course_test/cmake-build-debug /home/danila/CLionProjects/course_test/cmake-build-debug/CMakeFiles/course_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/course_test.dir/depend

