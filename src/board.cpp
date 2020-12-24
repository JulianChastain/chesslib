#include "board.h"

void boarditer::update(){
    row = false;
    if(idx % 8 == 0) {
        row = true;
        if (idx == 8)
            done = true;
        idx -= 16;
    }
}

void boarditer::operator+=(unsigned char c) {
    idx += c;
    update();
}

boarditer boarditer::operator++() {
    idx++;
    update();
    return *this;
}

board::board(std::string & fen){
    boarditer i;
	for(char c: fen){
		if(c != '/'){
			if(c >= '1' && c <= '9')
                i += c - '0';
			else{
                b[i.idx] = piece(c);
                ++i;
			}
        }
		if(i.done)
		    break;
    }
}

std::string board::str(){
	std::string val = "+-+-+-+-+-+-+-+-+\n";
	boarditer i;
	while(!i.done){
		val = val.append(1, '|');
		val = val.append(1, b[i.idx].sym());
		++i;
		if(i.row)
			val = val.append("|\n+-+-+-+-+-+-+-+-+\n");
	}
	return val;
}
