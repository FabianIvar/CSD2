cmake_minimum_required(VERSION 3.10)
project(dynAlloc)

add_executable(dynAlloc dynamic_allocation_test.cpp)
set_property(TARGET dynAlloc PROPERTY CXX_STANDARD 20)
