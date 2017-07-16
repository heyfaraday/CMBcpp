cmake_minimum_required(VERSION 3.7)
project(CMBcpp)

set(CMAKE_CXX_STANDARD 14)

# Flags
set(CMAKE_CXX_FLAGS "-Weverything -Ofast")

# Healpix
include_directories(/usr/local/cHealpix/include)
include_directories(/usr/local/Cellar/healpix/3.31/include/healpix_cxx)

# FFTW3 and HEALPIX_CXX
set(CMAKE_EXE_LINKER_FLAGS "-lfftw3l -lhealpix_cxx")

# Initial main.cpp
set(SOURCE_FILES main.cpp)
add_executable(CMBcpp ${SOURCE_FILES})

# Lib
add_subdirectory(lib)

# Link lib
include_directories(lib)

# Tests
add_subdirectory(test)