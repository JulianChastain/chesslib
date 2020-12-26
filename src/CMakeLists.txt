cmake_minimum_required(VERSION 3.10)

project(ChessLib)
set(CMAKE_CXX_STANDARD 20)

add_executable(testStructures ../tests/testStructures.cpp structures.cpp)
add_executable(basicChess ../tests/basicchess.cpp game.cpp includes/game.h structures.cpp)
