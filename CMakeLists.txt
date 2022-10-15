cmake_minimum_required(VERSION 3.23)
project(parallelized_cousins)

set(CMAKE_CXX_STANDARD 14)

add_executable(parallelized_cousins main.cpp PrimeGenerator.cpp Parallelized.cpp PrimeGenerator.h Parallelized.h)
