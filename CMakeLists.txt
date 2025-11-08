cmake_minimum_required(VERSION 3.18)
project(AoC24 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(./lib/aoc_toolbox)
add_subdirectory(./day-1)
add_subdirectory(./day-2)
add_subdirectory(./day-3)
