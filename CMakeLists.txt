cmake_minimum_required(VERSION 3.21)
project(COMP348_Assignment1_C C)

set(CMAKE_C_STANDARD 23)

add_executable(COMP348_Assignment1_C Question3.c AGGREGATE.h AGGREGATE.c Question5.c Question4.c)
