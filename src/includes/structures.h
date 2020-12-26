//
// Created by Julian Chastain on 12/25/2020.
//
#include <string>
#include <bitset>
#include <array>
#ifndef CHESSLIB_STRUCTURES_H
#define CHESSLIB_STRUCTURES_H

struct square {
    unsigned short idx; // Representing the index on a board array this square is at
    /*
     * Pre: s matches regex:"[a-h][1-8]" if algebraic, else "(qr|qn|qb|q|k|kb|kn|kr)[1-8]" case insensitive
     * Post: idx = the square represented by s
     */
    explicit square(std::string s = "a1", bool algebraic = true);
};

class piece {
public:
    std::bitset<4> val;
    char sym() const; //Post: sym = the char that represents the piece stored by val
    explicit piece(std::bitset<4> value): val(value){} //Post: value is stored as val
    explicit piece(char sym = ' '); //pre: sym = (K|Q|B|N|P) post: val stores that piece
    piece pop(); //post: val = 0000 [empty] and pop = sym()
};

struct move {
    square origin, destination;
    piece promotion;
    /*
     * Pre:m is a string representation of a move, in the format, algebraic, long algebraic (default), or descriptive
     * Post: The origin and destination are set based on the value of m
     */
    explicit move(std::string & m, bool long_algebraic = true);
    bool operator==(const move & other) const;
};

class board {
public:
    /*
     * Pre: fen is a string that holds a valid fen board state as its value
     * Post: Each element of b is initialized to the value of that square
     */
    board(std::string fen);
    std::array<piece, 64> b;
    std::string str(); //Post str = an ascii representation of the board state
    /*
     * Pre: The squares referenced bym are valid squares on the board
     * Post: destination square = m.pop() if m.promotion == empty, else m.promotion
     */
    void basic_move(move m);
};

//TODO refactor this to use traditional c++ iterators
struct boarditer {
    unsigned short idx;
    bool done, row;
    boarditer(): idx(56), done(false), row(false){}
    //Post:Increment idx by c, wrapping if needed
    void operator+=(unsigned char c);
    //Post: Incremenet idx, wrapping if needed
    boarditer operator++();
private:
    void update();
};


#endif //CHESSLIB_STRUCTURES_H
