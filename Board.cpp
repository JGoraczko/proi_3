//
// Created by jakub on 29.05.19.
//

#include "Board.h"


Board::Board(array<int,2> n_size){
    size = n_size;
}
vector<Piece*> Board::getPieces(){
    return pieces;
}
array<int, 2> Board::getSize(){
    return size;
}

void Board::add(Piece* b){
    pieces.push_back(b);
}
bool Board::doesItFit(array<int, 2> x){
    return (x[0] >= 0) && (x[0] < size[0]) && (x[1] >= 0) &&(x[1] < size[1]);
}


