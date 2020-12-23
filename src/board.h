#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <array>
#include "piece.h"
#include <string>

class board {
public:
  std::array<piece, 64> b;
  board(std::string & fen);
  std::string & str();
};

#endif
