cmake_minimum_required(VERSION 3.10)
project(vectorTest)

add_executable(vectorTest utils.cpp)
set_property(TARGET vectorTest PROPERTY CXX_STANDARD 20)
