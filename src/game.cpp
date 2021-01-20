// Created by Julian Chastain on 12/24/2020.
#include <sstream>
#include <algorithm>
#include "game.h"

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
void moveNode<t>::add(t begin, t end){
	count++;
	auto it = find_if(nextMoves.begin(), nextMoves.end(), [begin](moveNode x){return x.val == *begin;});
	if(it != nextMoves.end()){
		it -> add(++begin, end);
	}
}

template<class t>
moveNode<t>::moveNode(): count(0) {
	nextMoves.clear();
	val = move("e2e4");
}

template<class t>
moveNode<t>::moveNode(t begin, t end): count(0){
	if(begin == end)
		count = 0;
	else{
		count = 1;
		val = *begin;
		nextMoves.push_back(moveNode(begin++, end));
	}

}

void gameCombinator::add(game g){
	root.add(g.moves.begin(), g.moves.end());
}

std::string gameCombinator::openingRepertoire(){
		//TODO add code here
		return std::string("stub");
}
