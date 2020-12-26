//
// Created by Julian Chastain on 12/24/2020.
//
#include <sstream>
#include <algorithm>
#include "includes/game.h"

game::game(std::string & pgn, board starter): start(starter){
    std::istringstream ss(pgn);
    std::string temp;
    while(ss >> temp)
        moves.emplace_back(move(temp));
}

board game::positionAfter(short n_plies){
    board temp(start);
    for(auto it = moves.begin(); std::distance(moves.begin(), it) < n_plies; it++)
        temp.basic_move(*it);
    return temp;
}

template<class t>
void moveNode<t>::add(t it){
    nextMoves.push_back(it);
    count++;
}

template<class t>
moveNode<t>::moveNode(): count(0){
    nextMoves.clear();
}

gameCombinator::gameCombinator(game g){
    root.add(g.moves.begin());
}

void gameCombinator::add(game g){
    auto curNode = root;
    auto moves_iter = g.moves.begin();
    for(auto idx = std::find_if(curNode.nextMoves.begin(), curNode.nextMoves.end(), [moves_iter](auto idx){return *moves_iter == *idx;}); idx != curNode.nextMoves.end(); idx = std::find_if(curNode.nextMoves.begin(), curNode.nextMoves.end(), [moves_iter](auto idx){return *moves_iter == *idx;})){
        curNode.count++;

        moves_iter++;
    }
    curNode.add(moves_iter);
}