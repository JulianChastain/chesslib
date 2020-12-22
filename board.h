class board {
  std::array<piece, 64> b;
  board(string & fen);
  string & str();
};
