//
// Created by jakub on 29.05.19.
//

#include "Board.h"
#include "Piece.h"

void Board::remove(Piece* b){
    for(vector<Piece*>::iterator i = pieces.begin(); i < pieces.end(); ++i)
        if(b == *i)
            pieces.erase(i);
}

Piece* Board::whoStands(array<int, 2> x){
    for(Piece* b: pieces)
        if(b->getPosition() == x)
            return b;
    return 0;
}

void Board::makeMove(Move current_move){
    Piece* captured = this->whoStands(current_move.getWhere());
    if(captured)
        this->remove(captured);
    current_move.getWho()->push(current_move.getWhere());
    current_move.getWho()->setMoved();
}