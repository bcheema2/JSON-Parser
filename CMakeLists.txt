cmake_minimum_required(VERSION 3.5)
project(JSON_Parser)

set(CMAKE_CXX_STANDARD 23)

add_executable(JSON_Parser main.cpp
        include/Container.hpp
)

include_directories(include)