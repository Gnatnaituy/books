cmake_minimum_required(VERSION 3.8)
project(K_R)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Chapter_1 Chapter_2 Chapter_2
        Chapter_3 Chapter_4 Chapter_5 Chapter_6
        Chapter_7 Chapter_8 Practices)
add_executable(K_R ${SOURCE_FILES})