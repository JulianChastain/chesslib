//
// Created by Julian Chastain on 12/24/2020.
//

#ifndef CHESSLIB_GAME_H
#define CHESSLIB_GAME_H
#include <list>
#include <vector>
#include "structures.h"


class game {
public:
	std::list<move> moves;
	board start;
	game(std::string & pgn, board starter = std::string("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"));
	board positionAfter(short n_plies);
};

template <class t>
class moveNode {
public:
	std::vector<moveNode> nextMoves;
	short count;
	move val;
	moveNode();
	moveNode(t begin, t end);
	void add(t begin, t end);
};

class gameCombinator {
	moveNode<std::_List_iterator<move>> root;
	void add(game g);
	std::string openingRepertoire();
};


#endif //CHESSLIB_GAME_H
