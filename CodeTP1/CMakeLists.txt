cmake_minimum_required(VERSION 3.5)
project(TP1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Labyrinthe.cpp
    Labyrinthe.h
    Piece.cpp
    Piece.h
    Porte.cpp
    Porte.h
    Principal.cpp
)

add_executable(TP1 ${SOURCE_FILES})
