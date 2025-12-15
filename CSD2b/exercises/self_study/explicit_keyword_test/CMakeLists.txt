cmake_minimum_required(VERSION 3.10)
project(explTest)

add_executable(explTest explicit_keyword_test.cpp)
set_property(TARGET explTest PROPERTY CXX_STANDARD 20)
