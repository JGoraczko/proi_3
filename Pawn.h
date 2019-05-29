//
// Created by jakub on 29.05.19.
//

#ifndef PROI_3_PAWN_H
#define PROI_3_PAWN_H
#include <vector>
#include <array>
#include "Move.h"
#include "Board.h"
#include "Piece.h"

using namespace std;

class Pawn: public Piece{
public:
    Pawn(char, array<int, 2>);
    vector<Move> moves(Board);
};

#endif //PROI_3_PAWN_H
