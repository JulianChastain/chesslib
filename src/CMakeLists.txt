cmake_minimum_required(VERSION 3.10)

project(ChessLib)
set(CMAKE_CXX_STANDARD 20)

add_executable(boardTest ../tests/boardtest.cpp structures.cpp)
add_executable(basicChess ../tests/basicchess.cpp game.cpp includes/game.h structures.cpp)
