#include <iostream>
#include "board.h"

int main(){
  std::string pos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
  board b(pos);
  std::cout << b.str();
  return 0;
}
