# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/max/projects++/LodeRunner

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/max/projects++/LodeRunner/build

# Include any dependencies generated for this target.
include CMakeFiles/LodeRunner.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LodeRunner.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LodeRunner.dir/flags.make

CMakeFiles/LodeRunner.dir/sources/game.cpp.o: CMakeFiles/LodeRunner.dir/flags.make
CMakeFiles/LodeRunner.dir/sources/game.cpp.o: ../sources/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/projects++/LodeRunner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LodeRunner.dir/sources/game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LodeRunner.dir/sources/game.cpp.o -c /home/max/projects++/LodeRunner/sources/game.cpp

CMakeFiles/LodeRunner.dir/sources/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LodeRunner.dir/sources/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/max/projects++/LodeRunner/sources/game.cpp > CMakeFiles/LodeRunner.dir/sources/game.cpp.i

CMakeFiles/LodeRunner.dir/sources/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LodeRunner.dir/sources/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/max/projects++/LodeRunner/sources/game.cpp -o CMakeFiles/LodeRunner.dir/sources/game.cpp.s

CMakeFiles/LodeRunner.dir/sources/Player.cpp.o: CMakeFiles/LodeRunner.dir/flags.make
CMakeFiles/LodeRunner.dir/sources/Player.cpp.o: ../sources/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/projects++/LodeRunner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LodeRunner.dir/sources/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LodeRunner.dir/sources/Player.cpp.o -c /home/max/projects++/LodeRunner/sources/Player.cpp

CMakeFiles/LodeRunner.dir/sources/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LodeRunner.dir/sources/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/max/projects++/LodeRunner/sources/Player.cpp > CMakeFiles/LodeRunner.dir/sources/Player.cpp.i

CMakeFiles/LodeRunner.dir/sources/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LodeRunner.dir/sources/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/max/projects++/LodeRunner/sources/Player.cpp -o CMakeFiles/LodeRunner.dir/sources/Player.cpp.s

CMakeFiles/LodeRunner.dir/sources/Guard.cpp.o: CMakeFiles/LodeRunner.dir/flags.make
CMakeFiles/LodeRunner.dir/sources/Guard.cpp.o: ../sources/Guard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/projects++/LodeRunner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LodeRunner.dir/sources/Guard.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LodeRunner.dir/sources/Guard.cpp.o -c /home/max/projects++/LodeRunner/sources/Guard.cpp

CMakeFiles/LodeRunner.dir/sources/Guard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LodeRunner.dir/sources/Guard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/max/projects++/LodeRunner/sources/Guard.cpp > CMakeFiles/LodeRunner.dir/sources/Guard.cpp.i

CMakeFiles/LodeRunner.dir/sources/Guard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LodeRunner.dir/sources/Guard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/max/projects++/LodeRunner/sources/Guard.cpp -o CMakeFiles/LodeRunner.dir/sources/Guard.cpp.s

CMakeFiles/LodeRunner.dir/sources/SpritesLoad.cpp.o: CMakeFiles/LodeRunner.dir/flags.make
CMakeFiles/LodeRunner.dir/sources/SpritesLoad.cpp.o: ../sources/SpritesLoad.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/projects++/LodeRunner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/LodeRunner.dir/sources/SpritesLoad.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LodeRunner.dir/sources/SpritesLoad.cpp.o -c /home/max/projects++/LodeRunner/sources/SpritesLoad.cpp

CMakeFiles/LodeRunner.dir/sources/SpritesLoad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LodeRunner.dir/sources/SpritesLoad.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/max/projects++/LodeRunner/sources/SpritesLoad.cpp > CMakeFiles/LodeRunner.dir/sources/SpritesLoad.cpp.i

CMakeFiles/LodeRunner.dir/sources/SpritesLoad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LodeRunner.dir/sources/SpritesLoad.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/max/projects++/LodeRunner/sources/SpritesLoad.cpp -o CMakeFiles/LodeRunner.dir/sources/SpritesLoad.cpp.s

CMakeFiles/LodeRunner.dir/sources/Level.cpp.o: CMakeFiles/LodeRunner.dir/flags.make
CMakeFiles/LodeRunner.dir/sources/Level.cpp.o: ../sources/Level.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/projects++/LodeRunner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/LodeRunner.dir/sources/Level.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LodeRunner.dir/sources/Level.cpp.o -c /home/max/projects++/LodeRunner/sources/Level.cpp

CMakeFiles/LodeRunner.dir/sources/Level.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LodeRunner.dir/sources/Level.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/max/projects++/LodeRunner/sources/Level.cpp > CMakeFiles/LodeRunner.dir/sources/Level.cpp.i

CMakeFiles/LodeRunner.dir/sources/Level.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LodeRunner.dir/sources/Level.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/max/projects++/LodeRunner/sources/Level.cpp -o CMakeFiles/LodeRunner.dir/sources/Level.cpp.s

# Object files for target LodeRunner
LodeRunner_OBJECTS = \
"CMakeFiles/LodeRunner.dir/sources/game.cpp.o" \
"CMakeFiles/LodeRunner.dir/sources/Player.cpp.o" \
"CMakeFiles/LodeRunner.dir/sources/Guard.cpp.o" \
"CMakeFiles/LodeRunner.dir/sources/SpritesLoad.cpp.o" \
"CMakeFiles/LodeRunner.dir/sources/Level.cpp.o"

# External object files for target LodeRunner
LodeRunner_EXTERNAL_OBJECTS =

LodeRunner: CMakeFiles/LodeRunner.dir/sources/game.cpp.o
LodeRunner: CMakeFiles/LodeRunner.dir/sources/Player.cpp.o
LodeRunner: CMakeFiles/LodeRunner.dir/sources/Guard.cpp.o
LodeRunner: CMakeFiles/LodeRunner.dir/sources/SpritesLoad.cpp.o
LodeRunner: CMakeFiles/LodeRunner.dir/sources/Level.cpp.o
LodeRunner: CMakeFiles/LodeRunner.dir/build.make
LodeRunner: Framework/libFrameworkRelease.so.0.0.1
LodeRunner: /usr/lib/x86_64-linux-gnu/libSDL2.so
LodeRunner: /usr/lib/x86_64-linux-gnu/libSDL2main.a
LodeRunner: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
LodeRunner: CMakeFiles/LodeRunner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/max/projects++/LodeRunner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable LodeRunner"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LodeRunner.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LodeRunner.dir/build: LodeRunner

.PHONY : CMakeFiles/LodeRunner.dir/build

CMakeFiles/LodeRunner.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LodeRunner.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LodeRunner.dir/clean

CMakeFiles/LodeRunner.dir/depend:
	cd /home/max/projects++/LodeRunner/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/max/projects++/LodeRunner /home/max/projects++/LodeRunner /home/max/projects++/LodeRunner/build /home/max/projects++/LodeRunner/build /home/max/projects++/LodeRunner/build/CMakeFiles/LodeRunner.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LodeRunner.dir/depend

