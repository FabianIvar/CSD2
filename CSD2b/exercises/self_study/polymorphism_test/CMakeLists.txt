cmake_minimum_required(VERSION 3.10)
project(polymorph)

add_executable(polymorph polymorphism_test.cpp)
set_property(TARGET polymorph PROPERTY CXX_STANDARD 20)
