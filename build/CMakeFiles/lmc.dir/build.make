# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lanzo/repos/lmc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lanzo/repos/lmc/build

# Include any dependencies generated for this target.
include CMakeFiles/lmc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lmc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lmc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lmc.dir/flags.make

CMakeFiles/lmc.dir/src/main.cpp.o: CMakeFiles/lmc.dir/flags.make
CMakeFiles/lmc.dir/src/main.cpp.o: /home/lanzo/repos/lmc/src/main.cpp
CMakeFiles/lmc.dir/src/main.cpp.o: CMakeFiles/lmc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/lanzo/repos/lmc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lmc.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lmc.dir/src/main.cpp.o -MF CMakeFiles/lmc.dir/src/main.cpp.o.d -o CMakeFiles/lmc.dir/src/main.cpp.o -c /home/lanzo/repos/lmc/src/main.cpp

CMakeFiles/lmc.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmc.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lanzo/repos/lmc/src/main.cpp > CMakeFiles/lmc.dir/src/main.cpp.i

CMakeFiles/lmc.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmc.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lanzo/repos/lmc/src/main.cpp -o CMakeFiles/lmc.dir/src/main.cpp.s

CMakeFiles/lmc.dir/src/lmc.cpp.o: CMakeFiles/lmc.dir/flags.make
CMakeFiles/lmc.dir/src/lmc.cpp.o: /home/lanzo/repos/lmc/src/lmc.cpp
CMakeFiles/lmc.dir/src/lmc.cpp.o: CMakeFiles/lmc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/lanzo/repos/lmc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lmc.dir/src/lmc.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lmc.dir/src/lmc.cpp.o -MF CMakeFiles/lmc.dir/src/lmc.cpp.o.d -o CMakeFiles/lmc.dir/src/lmc.cpp.o -c /home/lanzo/repos/lmc/src/lmc.cpp

CMakeFiles/lmc.dir/src/lmc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmc.dir/src/lmc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lanzo/repos/lmc/src/lmc.cpp > CMakeFiles/lmc.dir/src/lmc.cpp.i

CMakeFiles/lmc.dir/src/lmc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmc.dir/src/lmc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lanzo/repos/lmc/src/lmc.cpp -o CMakeFiles/lmc.dir/src/lmc.cpp.s

# Object files for target lmc
lmc_OBJECTS = \
"CMakeFiles/lmc.dir/src/main.cpp.o" \
"CMakeFiles/lmc.dir/src/lmc.cpp.o"

# External object files for target lmc
lmc_EXTERNAL_OBJECTS =

lmc: CMakeFiles/lmc.dir/src/main.cpp.o
lmc: CMakeFiles/lmc.dir/src/lmc.cpp.o
lmc: CMakeFiles/lmc.dir/build.make
lmc: CMakeFiles/lmc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/lanzo/repos/lmc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lmc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lmc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lmc.dir/build: lmc
.PHONY : CMakeFiles/lmc.dir/build

CMakeFiles/lmc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lmc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lmc.dir/clean

CMakeFiles/lmc.dir/depend:
	cd /home/lanzo/repos/lmc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lanzo/repos/lmc /home/lanzo/repos/lmc /home/lanzo/repos/lmc/build /home/lanzo/repos/lmc/build /home/lanzo/repos/lmc/build/CMakeFiles/lmc.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lmc.dir/depend

