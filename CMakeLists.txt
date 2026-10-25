cmake_minimum_required(VERSION 3.20)

project(McDriveControl)

add_executable(mc_control 
src/main.cpp
src/serial/serial_port.cpp
src/thread/periodic_thread.cpp)

target_include_directories(mc_control PRIVATE include)
target_compile_features(mc_control PRIVATE cxx_std_17)