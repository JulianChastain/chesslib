#include "board.h"

board::board(std::string & fen){
  unsigned short count = 56;
  for(char c: fen){
    if(c != '/'){
      if(c >= '1' && c <= '9')
	count += c - '1';
      else{
	b[count] = piece(c);
	count++;
      }
    }
    if(count >> 3)
      if(count == 8)
	break;
      count -= 16;
  }
}
