#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <array>
#include "piece.h"
#include <string>

class board {
public:
	std::array<piece, 64> b;
	explicit board(std::string & fen);
	std::string str();
};

void update(int & idx);


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
