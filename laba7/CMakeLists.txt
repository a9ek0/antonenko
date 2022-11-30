cmake_minimum_required(VERSION 3.23)
project(laba7 C)

set(CMAKE_C_STANDARD 99)

add_executable(laba7 1.c)

add_executable(3 3.c arrays.c)
add_executable(2 2.c arrays.c)
add_executable(1 1.c arrays.c)

add_executable(gematogosha gematogosha.c arrays.c)
add_executable(4 4.c arrays.c)