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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/name1e5s/Documents/Code/TiandiEBank/backend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/name1e5s/Documents/Code/TiandiEBank/backend/build

# Include any dependencies generated for this target.
include third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/compiler_depend.make

# Include the progress variables for this target.
include third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/progress.make

# Include the compile flags for this target's objects.
include third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/flags.make

third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.o: third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/flags.make
third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.o: ../third_party/wolfssl/wolfssl-5.0.0-stable/examples/echoclient/echoclient.c
third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.o: third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/name1e5s/Documents/Code/TiandiEBank/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.o"
	cd /Users/name1e5s/Documents/Code/TiandiEBank/backend/build/third_party/wolfssl/wolfssl-5.0.0-stable && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.o -MF CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.o.d -o CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.o -c /Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/examples/echoclient/echoclient.c

third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.i"
	cd /Users/name1e5s/Documents/Code/TiandiEBank/backend/build/third_party/wolfssl/wolfssl-5.0.0-stable && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/examples/echoclient/echoclient.c > CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.i

third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.s"
	cd /Users/name1e5s/Documents/Code/TiandiEBank/backend/build/third_party/wolfssl/wolfssl-5.0.0-stable && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/examples/echoclient/echoclient.c -o CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.s

# Object files for target echoclient
echoclient_OBJECTS = \
"CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.o"

# External object files for target echoclient
echoclient_EXTERNAL_OBJECTS =

../third_party/wolfssl/wolfssl-5.0.0-stable/examples/echoclient/echoclient: third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/examples/echoclient/echoclient.c.o
../third_party/wolfssl/wolfssl-5.0.0-stable/examples/echoclient/echoclient: third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/build.make
../third_party/wolfssl/wolfssl-5.0.0-stable/examples/echoclient/echoclient: third_party/wolfssl/wolfssl-5.0.0-stable/libwolfssl.a
../third_party/wolfssl/wolfssl-5.0.0-stable/examples/echoclient/echoclient: third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/name1e5s/Documents/Code/TiandiEBank/backend/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../../../third_party/wolfssl/wolfssl-5.0.0-stable/examples/echoclient/echoclient"
	cd /Users/name1e5s/Documents/Code/TiandiEBank/backend/build/third_party/wolfssl/wolfssl-5.0.0-stable && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/echoclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/build: ../third_party/wolfssl/wolfssl-5.0.0-stable/examples/echoclient/echoclient
.PHONY : third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/build

third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/clean:
	cd /Users/name1e5s/Documents/Code/TiandiEBank/backend/build/third_party/wolfssl/wolfssl-5.0.0-stable && $(CMAKE_COMMAND) -P CMakeFiles/echoclient.dir/cmake_clean.cmake
.PHONY : third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/clean

third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/depend:
	cd /Users/name1e5s/Documents/Code/TiandiEBank/backend/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/name1e5s/Documents/Code/TiandiEBank/backend /Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable /Users/name1e5s/Documents/Code/TiandiEBank/backend/build /Users/name1e5s/Documents/Code/TiandiEBank/backend/build/third_party/wolfssl/wolfssl-5.0.0-stable /Users/name1e5s/Documents/Code/TiandiEBank/backend/build/third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/echoclient.dir/depend
