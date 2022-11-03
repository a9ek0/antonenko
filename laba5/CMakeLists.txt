cmake_minimum_required(VERSION 3.23)
project(laba5 C)

set(CMAKE_C_STANDARD 99)

add_executable(main.c arrays.c)

add_executable(1 1.c arrays.c)
add_executable(2 2.c arrays.c)
add_executable(arrays arrays.c)
add_executable(3 3.c arrays.c)
add_executable(123 123.c arrays.c)