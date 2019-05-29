//
// Created by jakub on 29.05.19.
//


#ifndef PROI_3_MOVE_H
#define PROI_3_MOVE_H
#include <array>
using namespace std;

class Piece;
class Move{
    Piece* who;
    array<int, 2> where;
public:
    Move(Piece*, array<int, 2>);
    Move(const Move&);
    Piece* getWho();
    array<int, 2> getWhere();
};


#endif //PROI_3_MOVE_H
