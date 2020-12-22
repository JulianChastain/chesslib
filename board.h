#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <array>
#include <string>

class board {
  std::array<piece, 64> b;
  board(std::string & fen);
  std::string & str();
};

#endif
