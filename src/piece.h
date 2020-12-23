#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED
#include <bitset>

class piece {
  std::bitset<4> val;
  char sym();
  piece(char sym);
};

#endif
