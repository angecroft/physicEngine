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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/angecroft/Documents/physicEngine/Template-Imac3-MoteursPhysiques-PartyKel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/angecroft/Documents/physicEngine/Template-Imac3-MoteursPhysiques-PartyKel/build

# Include any dependencies generated for this target.
include CMakeFiles/flag_steady_initial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/flag_steady_initial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/flag_steady_initial.dir/flags.make

CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o: CMakeFiles/flag_steady_initial.dir/flags.make
CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o: ../src/flag_steady_initial.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/angecroft/Documents/physicEngine/Template-Imac3-MoteursPhysiques-PartyKel/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o -c /home/angecroft/Documents/physicEngine/Template-Imac3-MoteursPhysiques-PartyKel/src/flag_steady_initial.cpp

CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/angecroft/Documents/physicEngine/Template-Imac3-MoteursPhysiques-PartyKel/src/flag_steady_initial.cpp > CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.i

CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/angecroft/Documents/physicEngine/Template-Imac3-MoteursPhysiques-PartyKel/src/flag_steady_initial.cpp -o CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.s

CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o.requires:
.PHONY : CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o.requires

CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o.provides: CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o.requires
	$(MAKE) -f CMakeFiles/flag_steady_initial.dir/build.make CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o.provides.build
.PHONY : CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o.provides

CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o.provides.build: CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o

# Object files for target flag_steady_initial
flag_steady_initial_OBJECTS = \
"CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o"

# External object files for target flag_steady_initial
flag_steady_initial_EXTERNAL_OBJECTS =

flag_steady_initial: CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o
flag_steady_initial: CMakeFiles/flag_steady_initial.dir/build.make
flag_steady_initial: PartyKel/libPartyKel.a
flag_steady_initial: third-party/AntTweakBar/libAntTweakBar.a
flag_steady_initial: /usr/lib/x86_64-linux-gnu/libSDLmain.a
flag_steady_initial: /usr/lib/x86_64-linux-gnu/libSDL.so
flag_steady_initial: /usr/lib/x86_64-linux-gnu/libGLU.so
flag_steady_initial: /usr/lib/x86_64-linux-gnu/libGL.so
flag_steady_initial: /usr/lib/x86_64-linux-gnu/libSM.so
flag_steady_initial: /usr/lib/x86_64-linux-gnu/libICE.so
flag_steady_initial: /usr/lib/x86_64-linux-gnu/libX11.so
flag_steady_initial: /usr/lib/x86_64-linux-gnu/libXext.so
flag_steady_initial: /usr/lib/x86_64-linux-gnu/libGLEW.so
flag_steady_initial: CMakeFiles/flag_steady_initial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable flag_steady_initial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flag_steady_initial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/flag_steady_initial.dir/build: flag_steady_initial
.PHONY : CMakeFiles/flag_steady_initial.dir/build

CMakeFiles/flag_steady_initial.dir/requires: CMakeFiles/flag_steady_initial.dir/src/flag_steady_initial.cpp.o.requires
.PHONY : CMakeFiles/flag_steady_initial.dir/requires

CMakeFiles/flag_steady_initial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/flag_steady_initial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/flag_steady_initial.dir/clean

CMakeFiles/flag_steady_initial.dir/depend:
	cd /home/angecroft/Documents/physicEngine/Template-Imac3-MoteursPhysiques-PartyKel/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/angecroft/Documents/physicEngine/Template-Imac3-MoteursPhysiques-PartyKel /home/angecroft/Documents/physicEngine/Template-Imac3-MoteursPhysiques-PartyKel /home/angecroft/Documents/physicEngine/Template-Imac3-MoteursPhysiques-PartyKel/build /home/angecroft/Documents/physicEngine/Template-Imac3-MoteursPhysiques-PartyKel/build /home/angecroft/Documents/physicEngine/Template-Imac3-MoteursPhysiques-PartyKel/build/CMakeFiles/flag_steady_initial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/flag_steady_initial.dir/depend

