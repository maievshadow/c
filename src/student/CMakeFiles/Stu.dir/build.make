# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/maievshabu/study/c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maievshabu/study/c

# Include any dependencies generated for this target.
include src/student/CMakeFiles/Stu.dir/depend.make

# Include the progress variables for this target.
include src/student/CMakeFiles/Stu.dir/progress.make

# Include the compile flags for this target's objects.
include src/student/CMakeFiles/Stu.dir/flags.make

src/student/CMakeFiles/Stu.dir/student.c.o: src/student/CMakeFiles/Stu.dir/flags.make
src/student/CMakeFiles/Stu.dir/student.c.o: src/student/student.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maievshabu/study/c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/student/CMakeFiles/Stu.dir/student.c.o"
	cd /Users/maievshabu/study/c/src/student && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Stu.dir/student.c.o   -c /Users/maievshabu/study/c/src/student/student.c

src/student/CMakeFiles/Stu.dir/student.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Stu.dir/student.c.i"
	cd /Users/maievshabu/study/c/src/student && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/maievshabu/study/c/src/student/student.c > CMakeFiles/Stu.dir/student.c.i

src/student/CMakeFiles/Stu.dir/student.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Stu.dir/student.c.s"
	cd /Users/maievshabu/study/c/src/student && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/maievshabu/study/c/src/student/student.c -o CMakeFiles/Stu.dir/student.c.s

# Object files for target Stu
Stu_OBJECTS = \
"CMakeFiles/Stu.dir/student.c.o"

# External object files for target Stu
Stu_EXTERNAL_OBJECTS =

src/student/libStu.a: src/student/CMakeFiles/Stu.dir/student.c.o
src/student/libStu.a: src/student/CMakeFiles/Stu.dir/build.make
src/student/libStu.a: src/student/CMakeFiles/Stu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/maievshabu/study/c/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libStu.a"
	cd /Users/maievshabu/study/c/src/student && $(CMAKE_COMMAND) -P CMakeFiles/Stu.dir/cmake_clean_target.cmake
	cd /Users/maievshabu/study/c/src/student && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Stu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/student/CMakeFiles/Stu.dir/build: src/student/libStu.a

.PHONY : src/student/CMakeFiles/Stu.dir/build

src/student/CMakeFiles/Stu.dir/clean:
	cd /Users/maievshabu/study/c/src/student && $(CMAKE_COMMAND) -P CMakeFiles/Stu.dir/cmake_clean.cmake
.PHONY : src/student/CMakeFiles/Stu.dir/clean

src/student/CMakeFiles/Stu.dir/depend:
	cd /Users/maievshabu/study/c && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maievshabu/study/c /Users/maievshabu/study/c/src/student /Users/maievshabu/study/c /Users/maievshabu/study/c/src/student /Users/maievshabu/study/c/src/student/CMakeFiles/Stu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/student/CMakeFiles/Stu.dir/depend

