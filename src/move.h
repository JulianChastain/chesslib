//
// Created by Julian Chastain on 12/24/2020.
//

#ifndef CHESSLIB_MOVE_H
#define CHESSLIB_MOVE_H
#include "square.h"
#include "piece.h"
#include <bitset>
#include <string>

struct move {
    square origin, destination;
    piece principle, promotion;
    std::bitset<3> row, col;
    bool check, mate;
    explicit move(std::string & m, bool long_algebraic = true);
};

#endif //CHESSLIB_MOVE_H
