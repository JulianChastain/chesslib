#include <iostream>
#include <string>
//
// Created by Julian Chastain on 12/24/2020.
//
#include "../src/includes/structures.h"

int main(){
    std::string pos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    board b(pos);
    std::string m;
    while(true){
        std::cout << b.str();
        std::cin >> m;
        b.basic_move(move(m));
    }
}

