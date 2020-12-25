#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <array>
#include <string>
#include "piece.h"
#include "move.h"

class board {
public:
	std::array<piece, 64> b;
	explicit board(std::string & fen);
	std::string str();
	void basic_move(move m);
};



struct boarditer {
    unsigned short idx;
    bool done, row;
    boarditer(): idx(56), done(false), row(false){}
    void operator+=(unsigned char c);
    boarditer operator++();
private:
    void update();
};

#endif
