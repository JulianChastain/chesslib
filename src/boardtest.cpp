#include <iostream>
#include "board.h"

int main(){
	std::string pos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
	board b(pos);

	std::cout << b.str();
//    for(boarditer b; !b.done; ++b){
//        if(b.row)
//            std::cout << std::endl;
//        std::cout << b.idx << "\t";
//    }

	return 0;
}
