#include "move.h"

move::move(std::string & m, bool long_algebraic){
    origin = square(m.substr(0,2));
    destination = square(m.substr(2,4));
}

