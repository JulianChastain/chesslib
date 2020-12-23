#include "board.h"

//TODO refactor with custom iterator
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
    if(count % 8 == 0){
      if(count == 8)
	break;
      count -= 16;
    }
  }
}

std::string board::str(){
  std::string val = "+-+-+-+-+-+-+-+\n";
  for(int i = 56; i > 0; i++){
    val = val.append(1, '|');
    val = val.append(1, b[i].sym());
    if(i % 8 == 7){
      val = val.append("|\n+-+-+-+-+-+-+-+\n");
      i -= 15;
    }
  }
  return val;
}
