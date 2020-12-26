//
// Created by Julian Chastain on 12/24/2020.
//

#ifndef CHESSLIB_GAME_H
#define CHESSLIB_GAME_H
#include <list>
#include <vector>
#include "includes/structures.h"


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
    std::vector<t> nextMoves;
    short count;
    moveNode();
    void add(t it);
};

class gameCombinator {
    moveNode<std::_List_iterator<move>> root;
    gameCombinator(game g);
    void add(game g);
};


#endif //CHESSLIB_GAME_H
