//
// Created by jakub on 29.05.19.
//

#include "Move.h"



Move::Move(Piece* n_who, array<int,2>n_where){
    who = n_who;
    where = n_where;
}
Move::Move(const Move& r){
    who = r.who;
    where = r.where;
}
Piece* Move::getWho(){
    return who;
}
array<int, 2> Move::getWhere(){
    return where;
}
