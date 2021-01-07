#include <iostream>
#include <cassert>
#include "../src/includes/structures.h"

void board_test_suite(){
    std::string pos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    board b(pos);
    std::string comp = "+-+-+-+-+-+-+-+-+\n|r|n|b|q|k|b|n|r|\n+-+-+-+-+-+-+-+-+\n|p|p|p|p|p|p|p|p|\n+-+-+-+-+-+-+-+-+\n| | | | | | | | |\n+-+-+-+-+-+-+-+-+\n| | | | | | | | |\n+-+-+-+-+-+-+-+-+\n| | | | | | | | |\n+-+-+-+-+-+-+-+-+\n| | | | | | | | |\n+-+-+-+-+-+-+-+-+\n|P|P|P|P|P|P|P|P|\n+-+-+-+-+-+-+-+-+\n|R|N|B|Q|K|B|N|R|\n+-+-+-+-+-+-+-+-+\n";
    assert(b.str() == comp);
}

void square_test_suite(){
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
    assert(zero == zero);
    assert(thirteen != twentysix);
}

void piece_test_suite(){
    piece q;
    piece p = 'K';
    assert(p == 'K');
    assert(p.sym() == 'K');
    assert(p.pop() == 'K');
    assert(p == q);
}

void move_test_suite(){
    move m1(std::string("e2e4"));
    move m2(std::string("e2e4Q"));
    move m3(std::string("e2e4Q"));
    //assert(m1 != m2);
    assert(m3 == m2);
}

int main(){
	board_test_suite();
	square_test_suite();
	piece_test_suite();
	move_test_suite();
}
