#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED
#include <bitset>

class piece {
public:
	std::bitset<4> val;
	char sym() const;
	explicit piece(char sym = ' ');
};

#endif
