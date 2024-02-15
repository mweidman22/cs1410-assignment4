cmake_minimum_required(VERSION 3.10)
project(cs1410_starter_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(main src/main.cpp)
