cmake_minimum_required(VERSION 3.30)
project(Hangman C)

set(CMAKE_C_STANDARD 11)

add_executable(Hangman main.c
        GameFunctions.c
        GameFunctions.h)
