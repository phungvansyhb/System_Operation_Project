# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/phungsy/Documents/C-C++_Trainnning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/phungsy/Documents/C-C++_Trainnning/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/C_C___Traninning_calc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/C_C___Traninning_calc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C_C___Traninning_calc.dir/flags.make

CMakeFiles/C_C___Traninning_calc.dir/calc.c.o: CMakeFiles/C_C___Traninning_calc.dir/flags.make
CMakeFiles/C_C___Traninning_calc.dir/calc.c.o: ../calc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/phungsy/Documents/C-C++_Trainnning/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/C_C___Traninning_calc.dir/calc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C_C___Traninning_calc.dir/calc.c.o   -c /home/phungsy/Documents/C-C++_Trainnning/calc.c

CMakeFiles/C_C___Traninning_calc.dir/calc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C_C___Traninning_calc.dir/calc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/phungsy/Documents/C-C++_Trainnning/calc.c > CMakeFiles/C_C___Traninning_calc.dir/calc.c.i

CMakeFiles/C_C___Traninning_calc.dir/calc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C_C___Traninning_calc.dir/calc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/phungsy/Documents/C-C++_Trainnning/calc.c -o CMakeFiles/C_C___Traninning_calc.dir/calc.c.s

# Object files for target C_C___Traninning_calc
C_C___Traninning_calc_OBJECTS = \
"CMakeFiles/C_C___Traninning_calc.dir/calc.c.o"

# External object files for target C_C___Traninning_calc
C_C___Traninning_calc_EXTERNAL_OBJECTS =

C_C___Traninning_calc: CMakeFiles/C_C___Traninning_calc.dir/calc.c.o
C_C___Traninning_calc: CMakeFiles/C_C___Traninning_calc.dir/build.make
C_C___Traninning_calc: CMakeFiles/C_C___Traninning_calc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/phungsy/Documents/C-C++_Trainnning/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable C_C___Traninning_calc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/C_C___Traninning_calc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C_C___Traninning_calc.dir/build: C_C___Traninning_calc

.PHONY : CMakeFiles/C_C___Traninning_calc.dir/build

CMakeFiles/C_C___Traninning_calc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/C_C___Traninning_calc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/C_C___Traninning_calc.dir/clean

CMakeFiles/C_C___Traninning_calc.dir/depend:
	cd /home/phungsy/Documents/C-C++_Trainnning/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/phungsy/Documents/C-C++_Trainnning /home/phungsy/Documents/C-C++_Trainnning /home/phungsy/Documents/C-C++_Trainnning/cmake-build-debug /home/phungsy/Documents/C-C++_Trainnning/cmake-build-debug /home/phungsy/Documents/C-C++_Trainnning/cmake-build-debug/CMakeFiles/C_C___Traninning_calc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/C_C___Traninning_calc.dir/depend

