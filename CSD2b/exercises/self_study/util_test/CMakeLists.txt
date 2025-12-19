cmake_minimum_required(VERSION 3.10)
project(utilTest)

add_executable(utilTest main.cpp utils.cpp)
set_property(TARGET utilTest PROPERTY CXX_STANDARD 20)
