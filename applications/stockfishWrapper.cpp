//
// Created by julian on 1/20/21.
//
//Purpose of this application is to let you play a game with stockfish
#include <iostream>
#include <fstream>
#define stockfish_name "stockfish12"
using namespace std;
int main(){
    //Construct a stream object
    fstream stockfish;
    //Connect the stream object to an IO device (2 in this case)
    stockfish.open(stockfish_name, ios::in|ios::out);
    //Perform IO operations on the stream
    //Disconnect the stream from an io device
    //Free the stream
}

