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
CMAKE_SOURCE_DIR = /home/parallels/video/muduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parallels/video/muduo/build

# Include any dependencies generated for this target.
include CMakeFiles/mymuduo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mymuduo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mymuduo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mymuduo.dir/flags.make

CMakeFiles/mymuduo.dir/Channel.cc.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/Channel.cc.o: ../Channel.cc
CMakeFiles/mymuduo.dir/Channel.cc.o: CMakeFiles/mymuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mymuduo.dir/Channel.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mymuduo.dir/Channel.cc.o -MF CMakeFiles/mymuduo.dir/Channel.cc.o.d -o CMakeFiles/mymuduo.dir/Channel.cc.o -c /home/parallels/video/muduo/Channel.cc

CMakeFiles/mymuduo.dir/Channel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/Channel.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/muduo/Channel.cc > CMakeFiles/mymuduo.dir/Channel.cc.i

CMakeFiles/mymuduo.dir/Channel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/Channel.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/muduo/Channel.cc -o CMakeFiles/mymuduo.dir/Channel.cc.s

CMakeFiles/mymuduo.dir/CurrentThread.cc.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/CurrentThread.cc.o: ../CurrentThread.cc
CMakeFiles/mymuduo.dir/CurrentThread.cc.o: CMakeFiles/mymuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mymuduo.dir/CurrentThread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mymuduo.dir/CurrentThread.cc.o -MF CMakeFiles/mymuduo.dir/CurrentThread.cc.o.d -o CMakeFiles/mymuduo.dir/CurrentThread.cc.o -c /home/parallels/video/muduo/CurrentThread.cc

CMakeFiles/mymuduo.dir/CurrentThread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/CurrentThread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/muduo/CurrentThread.cc > CMakeFiles/mymuduo.dir/CurrentThread.cc.i

CMakeFiles/mymuduo.dir/CurrentThread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/CurrentThread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/muduo/CurrentThread.cc -o CMakeFiles/mymuduo.dir/CurrentThread.cc.s

CMakeFiles/mymuduo.dir/DefaultPoller.cc.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/DefaultPoller.cc.o: ../DefaultPoller.cc
CMakeFiles/mymuduo.dir/DefaultPoller.cc.o: CMakeFiles/mymuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mymuduo.dir/DefaultPoller.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mymuduo.dir/DefaultPoller.cc.o -MF CMakeFiles/mymuduo.dir/DefaultPoller.cc.o.d -o CMakeFiles/mymuduo.dir/DefaultPoller.cc.o -c /home/parallels/video/muduo/DefaultPoller.cc

CMakeFiles/mymuduo.dir/DefaultPoller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/DefaultPoller.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/muduo/DefaultPoller.cc > CMakeFiles/mymuduo.dir/DefaultPoller.cc.i

CMakeFiles/mymuduo.dir/DefaultPoller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/DefaultPoller.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/muduo/DefaultPoller.cc -o CMakeFiles/mymuduo.dir/DefaultPoller.cc.s

CMakeFiles/mymuduo.dir/EPollPoller.cc.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/EPollPoller.cc.o: ../EPollPoller.cc
CMakeFiles/mymuduo.dir/EPollPoller.cc.o: CMakeFiles/mymuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mymuduo.dir/EPollPoller.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mymuduo.dir/EPollPoller.cc.o -MF CMakeFiles/mymuduo.dir/EPollPoller.cc.o.d -o CMakeFiles/mymuduo.dir/EPollPoller.cc.o -c /home/parallels/video/muduo/EPollPoller.cc

CMakeFiles/mymuduo.dir/EPollPoller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/EPollPoller.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/muduo/EPollPoller.cc > CMakeFiles/mymuduo.dir/EPollPoller.cc.i

CMakeFiles/mymuduo.dir/EPollPoller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/EPollPoller.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/muduo/EPollPoller.cc -o CMakeFiles/mymuduo.dir/EPollPoller.cc.s

CMakeFiles/mymuduo.dir/EventLoop.cc.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/EventLoop.cc.o: ../EventLoop.cc
CMakeFiles/mymuduo.dir/EventLoop.cc.o: CMakeFiles/mymuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mymuduo.dir/EventLoop.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mymuduo.dir/EventLoop.cc.o -MF CMakeFiles/mymuduo.dir/EventLoop.cc.o.d -o CMakeFiles/mymuduo.dir/EventLoop.cc.o -c /home/parallels/video/muduo/EventLoop.cc

CMakeFiles/mymuduo.dir/EventLoop.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/EventLoop.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/muduo/EventLoop.cc > CMakeFiles/mymuduo.dir/EventLoop.cc.i

CMakeFiles/mymuduo.dir/EventLoop.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/EventLoop.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/muduo/EventLoop.cc -o CMakeFiles/mymuduo.dir/EventLoop.cc.s

CMakeFiles/mymuduo.dir/EventLoopThread.cc.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/EventLoopThread.cc.o: ../EventLoopThread.cc
CMakeFiles/mymuduo.dir/EventLoopThread.cc.o: CMakeFiles/mymuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/mymuduo.dir/EventLoopThread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mymuduo.dir/EventLoopThread.cc.o -MF CMakeFiles/mymuduo.dir/EventLoopThread.cc.o.d -o CMakeFiles/mymuduo.dir/EventLoopThread.cc.o -c /home/parallels/video/muduo/EventLoopThread.cc

CMakeFiles/mymuduo.dir/EventLoopThread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/EventLoopThread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/muduo/EventLoopThread.cc > CMakeFiles/mymuduo.dir/EventLoopThread.cc.i

CMakeFiles/mymuduo.dir/EventLoopThread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/EventLoopThread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/muduo/EventLoopThread.cc -o CMakeFiles/mymuduo.dir/EventLoopThread.cc.s

CMakeFiles/mymuduo.dir/InetAddress.cc.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/InetAddress.cc.o: ../InetAddress.cc
CMakeFiles/mymuduo.dir/InetAddress.cc.o: CMakeFiles/mymuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/mymuduo.dir/InetAddress.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mymuduo.dir/InetAddress.cc.o -MF CMakeFiles/mymuduo.dir/InetAddress.cc.o.d -o CMakeFiles/mymuduo.dir/InetAddress.cc.o -c /home/parallels/video/muduo/InetAddress.cc

CMakeFiles/mymuduo.dir/InetAddress.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/InetAddress.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/muduo/InetAddress.cc > CMakeFiles/mymuduo.dir/InetAddress.cc.i

CMakeFiles/mymuduo.dir/InetAddress.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/InetAddress.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/muduo/InetAddress.cc -o CMakeFiles/mymuduo.dir/InetAddress.cc.s

CMakeFiles/mymuduo.dir/Poller.cc.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/Poller.cc.o: ../Poller.cc
CMakeFiles/mymuduo.dir/Poller.cc.o: CMakeFiles/mymuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/mymuduo.dir/Poller.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mymuduo.dir/Poller.cc.o -MF CMakeFiles/mymuduo.dir/Poller.cc.o.d -o CMakeFiles/mymuduo.dir/Poller.cc.o -c /home/parallels/video/muduo/Poller.cc

CMakeFiles/mymuduo.dir/Poller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/Poller.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/muduo/Poller.cc > CMakeFiles/mymuduo.dir/Poller.cc.i

CMakeFiles/mymuduo.dir/Poller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/Poller.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/muduo/Poller.cc -o CMakeFiles/mymuduo.dir/Poller.cc.s

CMakeFiles/mymuduo.dir/TcpServer.cc.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/TcpServer.cc.o: ../TcpServer.cc
CMakeFiles/mymuduo.dir/TcpServer.cc.o: CMakeFiles/mymuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/mymuduo.dir/TcpServer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mymuduo.dir/TcpServer.cc.o -MF CMakeFiles/mymuduo.dir/TcpServer.cc.o.d -o CMakeFiles/mymuduo.dir/TcpServer.cc.o -c /home/parallels/video/muduo/TcpServer.cc

CMakeFiles/mymuduo.dir/TcpServer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/TcpServer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/muduo/TcpServer.cc > CMakeFiles/mymuduo.dir/TcpServer.cc.i

CMakeFiles/mymuduo.dir/TcpServer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/TcpServer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/muduo/TcpServer.cc -o CMakeFiles/mymuduo.dir/TcpServer.cc.s

CMakeFiles/mymuduo.dir/Thread.cc.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/Thread.cc.o: ../Thread.cc
CMakeFiles/mymuduo.dir/Thread.cc.o: CMakeFiles/mymuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/mymuduo.dir/Thread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mymuduo.dir/Thread.cc.o -MF CMakeFiles/mymuduo.dir/Thread.cc.o.d -o CMakeFiles/mymuduo.dir/Thread.cc.o -c /home/parallels/video/muduo/Thread.cc

CMakeFiles/mymuduo.dir/Thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/Thread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/muduo/Thread.cc > CMakeFiles/mymuduo.dir/Thread.cc.i

CMakeFiles/mymuduo.dir/Thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/Thread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/muduo/Thread.cc -o CMakeFiles/mymuduo.dir/Thread.cc.s

CMakeFiles/mymuduo.dir/Timestamp.cc.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/Timestamp.cc.o: ../Timestamp.cc
CMakeFiles/mymuduo.dir/Timestamp.cc.o: CMakeFiles/mymuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/mymuduo.dir/Timestamp.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mymuduo.dir/Timestamp.cc.o -MF CMakeFiles/mymuduo.dir/Timestamp.cc.o.d -o CMakeFiles/mymuduo.dir/Timestamp.cc.o -c /home/parallels/video/muduo/Timestamp.cc

CMakeFiles/mymuduo.dir/Timestamp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/Timestamp.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/muduo/Timestamp.cc > CMakeFiles/mymuduo.dir/Timestamp.cc.i

CMakeFiles/mymuduo.dir/Timestamp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/Timestamp.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/muduo/Timestamp.cc -o CMakeFiles/mymuduo.dir/Timestamp.cc.s

CMakeFiles/mymuduo.dir/logger.cc.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/logger.cc.o: ../logger.cc
CMakeFiles/mymuduo.dir/logger.cc.o: CMakeFiles/mymuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/mymuduo.dir/logger.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mymuduo.dir/logger.cc.o -MF CMakeFiles/mymuduo.dir/logger.cc.o.d -o CMakeFiles/mymuduo.dir/logger.cc.o -c /home/parallels/video/muduo/logger.cc

CMakeFiles/mymuduo.dir/logger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/logger.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/muduo/logger.cc > CMakeFiles/mymuduo.dir/logger.cc.i

CMakeFiles/mymuduo.dir/logger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/logger.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/muduo/logger.cc -o CMakeFiles/mymuduo.dir/logger.cc.s

CMakeFiles/mymuduo.dir/tmp.cc.o: CMakeFiles/mymuduo.dir/flags.make
CMakeFiles/mymuduo.dir/tmp.cc.o: ../tmp.cc
CMakeFiles/mymuduo.dir/tmp.cc.o: CMakeFiles/mymuduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/video/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/mymuduo.dir/tmp.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mymuduo.dir/tmp.cc.o -MF CMakeFiles/mymuduo.dir/tmp.cc.o.d -o CMakeFiles/mymuduo.dir/tmp.cc.o -c /home/parallels/video/muduo/tmp.cc

CMakeFiles/mymuduo.dir/tmp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mymuduo.dir/tmp.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/video/muduo/tmp.cc > CMakeFiles/mymuduo.dir/tmp.cc.i

CMakeFiles/mymuduo.dir/tmp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mymuduo.dir/tmp.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/video/muduo/tmp.cc -o CMakeFiles/mymuduo.dir/tmp.cc.s

# Object files for target mymuduo
mymuduo_OBJECTS = \
"CMakeFiles/mymuduo.dir/Channel.cc.o" \
"CMakeFiles/mymuduo.dir/CurrentThread.cc.o" \
"CMakeFiles/mymuduo.dir/DefaultPoller.cc.o" \
"CMakeFiles/mymuduo.dir/EPollPoller.cc.o" \
"CMakeFiles/mymuduo.dir/EventLoop.cc.o" \
"CMakeFiles/mymuduo.dir/EventLoopThread.cc.o" \
"CMakeFiles/mymuduo.dir/InetAddress.cc.o" \
"CMakeFiles/mymuduo.dir/Poller.cc.o" \
"CMakeFiles/mymuduo.dir/TcpServer.cc.o" \
"CMakeFiles/mymuduo.dir/Thread.cc.o" \
"CMakeFiles/mymuduo.dir/Timestamp.cc.o" \
"CMakeFiles/mymuduo.dir/logger.cc.o" \
"CMakeFiles/mymuduo.dir/tmp.cc.o"

# External object files for target mymuduo
mymuduo_EXTERNAL_OBJECTS =

../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/Channel.cc.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/CurrentThread.cc.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/DefaultPoller.cc.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/EPollPoller.cc.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/EventLoop.cc.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/EventLoopThread.cc.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/InetAddress.cc.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/Poller.cc.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/TcpServer.cc.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/Thread.cc.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/Timestamp.cc.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/logger.cc.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/tmp.cc.o
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/build.make
../lib/libmymuduo.so: CMakeFiles/mymuduo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parallels/video/muduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX shared library ../lib/libmymuduo.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mymuduo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mymuduo.dir/build: ../lib/libmymuduo.so
.PHONY : CMakeFiles/mymuduo.dir/build

CMakeFiles/mymuduo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mymuduo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mymuduo.dir/clean

CMakeFiles/mymuduo.dir/depend:
	cd /home/parallels/video/muduo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/video/muduo /home/parallels/video/muduo /home/parallels/video/muduo/build /home/parallels/video/muduo/build /home/parallels/video/muduo/build/CMakeFiles/mymuduo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mymuduo.dir/depend
