cmake_minimum_required(VERSION 3.23)
project(laba3 C)

set(CMAKE_C_STANDARD 99)

add_executable(laba3 1.c 2.c mass_functions.c mass_functions.h)

add_executable(1 1.c mass_functions.c mass_functions.h)
add_executable(2 2.c mass_functions.c mass_functions.h)
add_executable(3 3.c mass_functions.c mass_functions.h)