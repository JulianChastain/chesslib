#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include <string>

struct square {
    unsigned short idx;
    explicit square(std::string s = "a1", bool algebraic = true);
};
#endif
