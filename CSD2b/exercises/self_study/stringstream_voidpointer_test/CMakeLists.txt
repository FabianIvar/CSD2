cmake_minimum_required(VERSION 3.10)
project(staticTest)

add_executable(staticTest main.cpp)
set_property(TARGET staticTest PROPERTY CXX_STANDARD 20)
