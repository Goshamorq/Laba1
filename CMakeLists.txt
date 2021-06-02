cmake_minimum_required(VERSION 3.19)
project(Vans C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(Vans
        include/Vector3d.h
        Sources/main.c
        Sources/Vector3d.c Sources/Test.c)
