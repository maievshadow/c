# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/redredmaple/study

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/redredmaple/study

# Include any dependencies generated for this target.
include CMakeFiles/bin/Main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bin/Main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bin/Main.dir/flags.make

CMakeFiles/bin/Main.dir/src/main.c.o: CMakeFiles/bin/Main.dir/flags.make
CMakeFiles/bin/Main.dir/src/main.c.o: src/main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/redredmaple/study/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/bin/Main.dir/src/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/bin/Main.dir/src/main.c.o   -c /home/redredmaple/study/src/main.c

CMakeFiles/bin/Main.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bin/Main.dir/src/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/redredmaple/study/src/main.c > CMakeFiles/bin/Main.dir/src/main.c.i

CMakeFiles/bin/Main.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bin/Main.dir/src/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/redredmaple/study/src/main.c -o CMakeFiles/bin/Main.dir/src/main.c.s

CMakeFiles/bin/Main.dir/src/main.c.o.requires:
.PHONY : CMakeFiles/bin/Main.dir/src/main.c.o.requires

CMakeFiles/bin/Main.dir/src/main.c.o.provides: CMakeFiles/bin/Main.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/bin/Main.dir/build.make CMakeFiles/bin/Main.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/bin/Main.dir/src/main.c.o.provides

CMakeFiles/bin/Main.dir/src/main.c.o.provides.build: CMakeFiles/bin/Main.dir/src/main.c.o

# Object files for target bin/Main
bin/Main_OBJECTS = \
"CMakeFiles/bin/Main.dir/src/main.c.o"

# External object files for target bin/Main
bin/Main_EXTERNAL_OBJECTS =

bin/Main: CMakeFiles/bin/Main.dir/src/main.c.o
bin/Main: CMakeFiles/bin/Main.dir/build.make
bin/Main: src/student/libStu.a
bin/Main: src/list.1/libList.a
bin/Main: CMakeFiles/bin/Main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable bin/Main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bin/Main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bin/Main.dir/build: bin/Main
.PHONY : CMakeFiles/bin/Main.dir/build

CMakeFiles/bin/Main.dir/requires: CMakeFiles/bin/Main.dir/src/main.c.o.requires
.PHONY : CMakeFiles/bin/Main.dir/requires

CMakeFiles/bin/Main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bin/Main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bin/Main.dir/clean

CMakeFiles/bin/Main.dir/depend:
	cd /home/redredmaple/study && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/redredmaple/study /home/redredmaple/study /home/redredmaple/study /home/redredmaple/study /home/redredmaple/study/CMakeFiles/bin/Main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bin/Main.dir/depend
