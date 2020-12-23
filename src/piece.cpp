#include <string>
#include "piece.h"

const std::string empty = "0000";
const std::string wk = "1000";
const std::string wq = "0100";
const std::string wr = "1100";
const std::string wb = "0010";
const std::string wn = "1010";
const std::string wp = "1110";
const std::string bk = "1001";
const std::string bq = "0101";
const std::string br = "1101";
const std::string bb = "0011";
const std::string bn = "1011";
const std::string bp = "1111";
const std::string invalid = "0001";

piece::piece(char sym){
  switch (sym) {
  case ' ':
    val |= std::bitset<4>(empty);
    break;
  case 'K':
    val |= std::bitset<4>(wk);
    break;
  case 'Q':
    val |= std::bitset<4>(wq);
    break;
  case 'R':
    val |= std::bitset<4>(wr);
    break;
  case 'B':
    val |= std::bitset<4>(wb);
    break;
  case 'N':
    val |= std::bitset<4>(wn);
    break;
  case 'P':
    val |= std::bitset<4>(wp);
    break;
  case 'k':
    val |= std::bitset<4>(bk);
    break;
  case 'q':
    val |= std::bitset<4>(bq);
    break;
  case 'r':
    val |= std::bitset<4>(br);
    break;
  case 'b':
    val |= std::bitset<4>(bb);
    break;
  case 'n':
    val |= std::bitset<4>(bn);
    break;
  case 'p':
    val |= std::bitset<4>(bp);
    break;
  case '\0':
    val |= std::bitset<4>(invalid);
   } break;
  }

  
