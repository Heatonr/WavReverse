cmake_minimum_required(VERSION 3.15)
project(WavReverse C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(WavReverse
        file.c
        file.h
        main.c
        wav.c
        wav.h)
