cmake_minimum_required(VERSION 3.10)

project(ChessLib)
set(CMAKE_CXX_STANDARD 20)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")

endif()

add_executable(testStructures ../tests/testStructures.cpp cli/structures.cpp)
add_executable(basicChess ../tests/basicchess.cpp cli/game.cpp cli/game.h cli/structures.cpp)
add_executable(stockfishcli cli/game.cpp cli/structures.cpp ../applications/stockfishWrapper.cpp)
