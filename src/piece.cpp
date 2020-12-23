#include <unordered_map>
#include "piece.h"

const std::bitset<4> empty ("0000");
const std::bitset<4> wk ("1000");
const std::bitset<4> wq ("0100");
const std::bitset<4> wr ("1100");
const std::bitset<4> wb ("0010");
const std::bitset<4> wn ("1010");
const std::bitset<4> wp ("1110");
const std::bitset<4> invalid ("0001");
const std::bitset<4> bk ("1001");
const std::bitset<4> bq ("0101");
const std::bitset<4> br ("1101");
const std::bitset<4> bb ("0011");
const std::bitset<4> bn ("1011");
const std::bitset<4> bp ("1111");

piece::piece(char sym){
  switch (sym) {
  case ' ':
    val = empty;
    break;
  case 'K':
    val = wk;
    break;
  case 'Q':
    val = wq;
    break;
  case 'R':
    val = wr;
    break;
  case 'B':
    val = wb;
    break;
  case 'N':
    val = wn;
    break;
  case 'P':
    val = wp;
    break;
  case 'k':
    val = bk;
    break;
  case 'q':
    val = bq;
    break;
  case 'r':
    val = br;
    break;
  case 'b':
    val = bb;
    break;
  case 'n':
    val = bn;
    break;
  case 'p':
    val = bp;
    break;
  case '\0':
    val = invalid;
    break;
   }
  }

const std::unordered_map<std::bitset<4>, char> table = {
  {empty, ' '},
  {wk, 'K'},
  {wq, 'Q'},
  {wr, 'R'},
  {wb, 'B'},
  {wn, 'N'},
  {wp, 'P'},
  {invalid, '\0'},
  {wk, 'k'},
  {wq, 'q'},
  {wr, 'r'},
  {wb, 'b'},
  {wn, 'n'},
  {wp, 'p'}
};

char piece::sym() const{
  return table.at(val);
}

  
  
