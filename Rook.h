//
// Created by jakub on 29.05.19.
//

#ifndef PROI_3_ROOK_H
#define PROI_3_ROOK_H
#include <vector>
#include <array>
#include "Move.h"
#include "Board.h"
#include "Piece.h"

class Rook: public Piece{
public:
    Rook(char, array<int, 2>);
    vector<Move> moves(Board);
};

#endif //PROI_3_ROOK_H
