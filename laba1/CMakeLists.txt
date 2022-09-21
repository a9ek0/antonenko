cmake_minimum_required(VERSION 3.23)
project(laba1 C)

set(CMAKE_C_STANDARD 99)

add_executable(laba1 main.c 1.c 2.c 3.c 4.c)

add_executable(1 1.c)
add_executable(2 2.c)
add_executable(3 3.c)
add_executable(4 4.c)