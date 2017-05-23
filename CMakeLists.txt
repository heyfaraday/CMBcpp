cmake_minimum_required(VERSION 3.7)
project(CMBcpp)

set(CMAKE_CXX_STANDARD 14)

# Flags
set(CMAKE_CXX_FLAGS "-Weverything -Ofast")

# Initial main.cpp
set(SOURCE_FILES main.cpp)
add_executable(CMBcpp ${SOURCE_FILES})

# Lib
add_subdirectory(lib)

# Link lib
include_directories(lib)

# Tests
add_subdirectory(test)