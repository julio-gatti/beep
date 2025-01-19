cmake_minimum_required(VERSION 3.5)

project(beep)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(beep "beep/main.c")
add_executable(boop "boop/main.c")
