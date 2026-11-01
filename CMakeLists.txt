cmake_minimum_required(VERSION 3.20)

project(McDriveControl)

add_executable(mc_control 
src/main.cpp
src/serial/serial_port.cpp
src/thread/thread_timer.cpp
src/ui/user_interface.cpp
src/serial/frame_link.cpp
src/serial/frame.cpp)

target_include_directories(mc_control PRIVATE include)
target_compile_features(mc_control PRIVATE cxx_std_17)