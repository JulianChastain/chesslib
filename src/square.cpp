#include "square.h"

square::square(std::string s, bool algebraic): idx(0){
  if(algebraic)
    idx = (s[1] - '1') * 8 + ('a' - s[0]);
}
