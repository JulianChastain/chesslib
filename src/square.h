#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include <string>

struct square {
    unsigned short idx;
    square(std::string s, bool algebraic = true);
};
#endif
