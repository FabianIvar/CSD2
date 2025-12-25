cmake_minimum_required(VERSION 3.10)
project(main)

add_executable(main main.cpp utils.cpp)
set_property(TARGET main PROPERTY CXX_STANDARD 20)
