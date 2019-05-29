//
// Created by jakub on 29.05.19.
//

#ifndef PROI_3_PIECE_H
#define PROI_3_PIECE_H

#include <vector>
#include "Move.h"
#include "Board.h"

using namespace std;


class Piece{
    char colour;
protected:
    array<int, 2> position;
    char symbol;
    bool moved;
public:
    Piece(char, array<int, 2>);
    array<int, 2> getPosition();
    char getColour();
    char getSymbol();
    void push(array<int, 2>);
    void setMoved();
    virtual vector<Move> moves(Board) = 0;
    vector<Piece*> attacked(Board);  //wskazuje bierki atakujące rozważaną bierkę
};


#endif //PROI_3_PIECE_H
