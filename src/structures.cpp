//
// Created by Julian Chastain on 12/25/2020.
//
#include <unordered_map>
#include "includes/structures.h"
#define EMPTY std::bitset<4>("0000")
#define wk std::bitset<4>("1000")
#define wq std::bitset<4>("0100")
#define wr std::bitset<4>("1100")
#define wb std::bitset<4>("0010")
#define wn std::bitset<4>("1010")
#define wp std::bitset<4>("1110")
#define invalid std::bitset<4>("0001")
#define bk std::bitset<4>("1001")
#define bq std::bitset<4>("0101")
#define br std::bitset<4>("1101")
#define bb std::bitset<4>("0011")
#define bn std::bitset<4>("1011")
#define bp std::bitset<4>("1111")

piece piece::pop(){
    piece v(val);
    val.reset();
    return v;
}

piece::piece(char sym){
    switch (sym) {
        case ' ':
            val = EMPTY;
            break;
        case 'K':
            val = wk;
            break;
        case 'Q':
            val = wq;
            break;
        case 'R':
            val = wr;
            break;
        case 'B':
            val = wb;
            break;
        case 'N':
            val = wn;
            break;
        case 'P':
            val = wp;
            break;
        case 'k':
            val = bk;
            break;
        case 'q':
            val = bq;
            break;
        case 'r':
            val = br;
            break;
        case 'b':
            val = bb;
            break;
        case 'n':
            val = bn;
            break;
        case 'p':
            val = bp;
            break;
        default:
        case '\0':
            val = invalid;
            break;
    }
}

char piece::sym() const{
    static const std::unordered_map<std::bitset<4>, char> table = {
            {wk, 'K'},
            {wq, 'Q'},
            {wr, 'R'},
            {wb, 'B'},
            {wn, 'N'},
            {wp, 'P'},
            {bk, 'k'},
            {bq, 'q'},
            {br, 'r'},
            {bb, 'b'},
            {bn, 'n'},
            {bp, 'p'},
            {EMPTY, ' '},
            {invalid, '\0'}
    };
    return table.at(val);
}

bool piece::operator==(const piece &other) const {
    return val == val;
}

bool piece::operator==(const char other) const {
    return other == sym();
}

square::square(std::string s): idx(0){
    idx = (s[1] - '1') * 8 + (s[0] - 'a');
}

auto square::operator<=>(const square other) const{
    if(idx > other.idx)
        return std::strong_ordering::greater;
    if(idx < other.idx)
        return std::strong_ordering::less;
    return std::strong_ordering::equal;
}

move::move(std::string m){
    origin = square(m.substr(0,2));
    destination = square(m.substr(2,4));
    if(m.size() == 5)
        promotion = m[4];
    else
        promotion = EMPTY;
}

bool move::operator==(const move &other) const {
    return origin == other.origin && destination == other.destination && promotion == other.promotion;
}

void board::basic_move(move m) {
    piece temp = b[m.origin.idx].pop();
    b[m.destination.idx] = (m.promotion == ' ') ? temp : m.promotion;
}

void boarditer::update(){
    row = false;
    if(idx % 8 == 0) {
        row = true;
        if (idx == 8)
            done = true;
        idx -= 16;
    }
}

void boarditer::operator+=(unsigned char c) {
    idx += c;
    update();
}

boarditer boarditer::operator++() {
    idx++;
    update();
    return *this;
}

std::string board::str(){
    std::string val = "+-+-+-+-+-+-+-+-+\n";
    boarditer i;
    while(!i.done){
        val = val.append(1, '|');
        val = val.append(1, b[i.idx].sym());
        ++i;
        if(i.row)
            val = val.append("|\n+-+-+-+-+-+-+-+-+\n");
    }
    return val;
}

board::board(const std::string& fen) {
    boarditer i;
    for(char c: fen){
        if(c != '/'){
            if(c >= '1' && c <= '9')
                i += c - '0';
            else{
                b[i.idx] = piece(c);
                ++i;
            }
        }
        if(i.done)
            break;
    }
}
