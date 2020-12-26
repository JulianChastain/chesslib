#include <iostream>
#include <cassert>
#include "../src/includes/structures.h"

void basic_test_suite(board & b){
    std::string comp = "+-+-+-+-+-+-+-+-+\n|r|n|b|q|k|b|n|r|\n+-+-+-+-+-+-+-+-+\n|p|p|p|p|p|p|p|p|\n+-+-+-+-+-+-+-+-+\n| | | | | | | | |\n+-+-+-+-+-+-+-+-+\n| | | | | | | | |\n+-+-+-+-+-+-+-+-+\n| | | | | | | | |\n+-+-+-+-+-+-+-+-+\n| | | | | | | | |\n+-+-+-+-+-+-+-+-+\n|P|P|P|P|P|P|P|P|\n+-+-+-+-+-+-+-+-+\n|R|N|B|Q|K|B|N|R|\n+-+-+-+-+-+-+-+-+\n";
    assert(b.str() == comp);
    square zero("a1");
    square thirteen("f2");
    square twentysix("c4");
    square fiftyeight("c8");
    square sixtythree("h8");
    assert(zero.idx == 0);
    assert(thirteen.idx == 13);
    assert(twentysix.idx == 26);
    assert(fiftyeight.idx == 58);
    assert(sixtythree.idx == 63);
}

int main(){
	std::string pos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
	board b(pos);
	basic_test_suite(b);
}
