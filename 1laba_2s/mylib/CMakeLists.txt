cmake_minimum_required(VERSION 3.24)
project(mylib)

# Add all source files
file(GLOB SOURCES structure.c)

# Create a static library from the sources
add_library(mylib STATIC structure.c)

# Specify the directories in which to search for headers
target_include_directories(mylib PUBLIC include)
