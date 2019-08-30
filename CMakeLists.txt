cmake_minimum_required(VERSION 3.14)
project(BIT)

set(CMAKE_CXX_STANDARD 14)

include_directories(BIT include )

add_executable(BIT main.cpp include/BIT.hpp)