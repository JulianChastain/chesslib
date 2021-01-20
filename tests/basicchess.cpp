#include <iostream>
#include <string>
#include <vector>
//
// Created by Julian Chastain on 12/24/2020.
//
#include <cassert>
#include "../src/structures.h"

const std::vector<std::string> basic_moves = {"e2e4", "f1d3", "g1h3", "e1g1", "e4e5", "f7f5", "e5f6"};
const std::string pos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
std::string final_position(const std::vector<std::string>& moves){
	board b(pos);
	for(const std::string& s: moves)
		b.basic_move(move(s));
	return b.str();
}

void basicGame(){
	board b(pos);
	std::string input;
	while(true){
		std::cin >> input;
		b.basic_move(move(input));
		std::cout << b.str();
	}
}

int main(int argc, char ** argv){
	std::cout << final_position(basic_moves) << std::endl;
	assert(final_position(basic_moves) == "+-+-+-+-+-+-+-+-+\n"
					"|r|n|b|q|k|b|n|r|\n"
					"+-+-+-+-+-+-+-+-+\n"
					"|p|p|p|p|p| |p|p|\n"
					"+-+-+-+-+-+-+-+-+\n"
					"| | | | | |P| | |\n"
					"+-+-+-+-+-+-+-+-+\n"
					"| | | | | | | | |\n"
					"+-+-+-+-+-+-+-+-+\n"
					"| | | | | | | | |\n"
					"+-+-+-+-+-+-+-+-+\n"
					"| | | |B| | | |N|\n"
					"+-+-+-+-+-+-+-+-+\n"
					"|P|P|P|P| |P|P|P|\n"
					"+-+-+-+-+-+-+-+-+\n"
					"|R|N|B|Q| |R|K| |\n"
					"+-+-+-+-+-+-+-+-+\n");

	if(argc > 0 && argv[1][0] == 'g')
		basicGame();
	return 0;
}
