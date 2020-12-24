#include <iostream>
#include "board.h"
#include "square.h"
#include <assert.h>

int main(){
	std::string pos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
	board b(pos);

//    for(boarditer b; !b.done; ++b){
//        if(b.row)
//            std::cout << std::endl;
//        std::cout << b.idx << "\t";
//    }
	std::string comp = "+-+-+-+-+-+-+-+-+\n|p|p|p|p|p|p|p|p|\n+-+-+-+-+-+-+-+-+\n| | | | | | | | |\n+-+-+-+-+-+-+-+-+\n| | | | | | | | |\n+-+-+-+-+-+-+-+-+\n| | | | | | | | |\n+-+-+-+-+-+-+-+-+\n| | | | | | | | |\n+-+-+-+-+-+-+-+-+\n|P|P|P|P|P|P|P|P|\n+-+-+-+-+-+-+-+-+\n|R|N|B|Q|K|B|N|R|\n+-+-+-+-+-+-+-+-+\n";
	std::cout << comp;
	std::cout << b.str();
	assert(b.str() == comp);
	square zero("a1");
	square thirteen("f2");
	square twentysix("c4");
	square fiftyeight("d8");
	square sixtythree("h8");
	assert(zero.idx == 0);
	assert(thirteen.idx == 13);
	assert(twentysix.idx == 26);
	assert(fiftyeight.idx == 58);
	assert(sixtythree.idx == 0);
	
	return 0;
}
