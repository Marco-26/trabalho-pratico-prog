cmake_minimum_required(VERSION 3.22)
project(trabalho_pratico_prog C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(trabalho_pratico_prog
        game.c
        game.h
        main.c
        tempCodeRunnerFile.c)
