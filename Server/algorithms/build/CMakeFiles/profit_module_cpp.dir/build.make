# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/build

# Include any dependencies generated for this target.
include CMakeFiles/profit_module_cpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/profit_module_cpp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/profit_module_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/profit_module_cpp.dir/flags.make

CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.o: CMakeFiles/profit_module_cpp.dir/flags.make
CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.o: ../utils/courier.cpp
CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.o: CMakeFiles/profit_module_cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.o -MF CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.o.d -o CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.o -c /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/utils/courier.cpp

CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/utils/courier.cpp > CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.i

CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/utils/courier.cpp -o CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.s

CMakeFiles/profit_module_cpp.dir/utils/order.cpp.o: CMakeFiles/profit_module_cpp.dir/flags.make
CMakeFiles/profit_module_cpp.dir/utils/order.cpp.o: ../utils/order.cpp
CMakeFiles/profit_module_cpp.dir/utils/order.cpp.o: CMakeFiles/profit_module_cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/profit_module_cpp.dir/utils/order.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/profit_module_cpp.dir/utils/order.cpp.o -MF CMakeFiles/profit_module_cpp.dir/utils/order.cpp.o.d -o CMakeFiles/profit_module_cpp.dir/utils/order.cpp.o -c /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/utils/order.cpp

CMakeFiles/profit_module_cpp.dir/utils/order.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/profit_module_cpp.dir/utils/order.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/utils/order.cpp > CMakeFiles/profit_module_cpp.dir/utils/order.cpp.i

CMakeFiles/profit_module_cpp.dir/utils/order.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/profit_module_cpp.dir/utils/order.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/utils/order.cpp -o CMakeFiles/profit_module_cpp.dir/utils/order.cpp.s

CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.o: CMakeFiles/profit_module_cpp.dir/flags.make
CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.o: ../utils/profit_wrap.cpp
CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.o: CMakeFiles/profit_module_cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.o -MF CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.o.d -o CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.o -c /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/utils/profit_wrap.cpp

CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/utils/profit_wrap.cpp > CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.i

CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/utils/profit_wrap.cpp -o CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.s

# Object files for target profit_module_cpp
profit_module_cpp_OBJECTS = \
"CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.o" \
"CMakeFiles/profit_module_cpp.dir/utils/order.cpp.o" \
"CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.o"

# External object files for target profit_module_cpp
profit_module_cpp_EXTERNAL_OBJECTS =

libprofit_module_cpp.a: CMakeFiles/profit_module_cpp.dir/utils/courier.cpp.o
libprofit_module_cpp.a: CMakeFiles/profit_module_cpp.dir/utils/order.cpp.o
libprofit_module_cpp.a: CMakeFiles/profit_module_cpp.dir/utils/profit_wrap.cpp.o
libprofit_module_cpp.a: CMakeFiles/profit_module_cpp.dir/build.make
libprofit_module_cpp.a: CMakeFiles/profit_module_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libprofit_module_cpp.a"
	$(CMAKE_COMMAND) -P CMakeFiles/profit_module_cpp.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/profit_module_cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/profit_module_cpp.dir/build: libprofit_module_cpp.a
.PHONY : CMakeFiles/profit_module_cpp.dir/build

CMakeFiles/profit_module_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/profit_module_cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/profit_module_cpp.dir/clean

CMakeFiles/profit_module_cpp.dir/depend:
	cd /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/build /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/build /home/sandborg/uniCode/Profit-Optimized-Meal-Ordering-System/Server/algorithms/build/CMakeFiles/profit_module_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/profit_module_cpp.dir/depend

