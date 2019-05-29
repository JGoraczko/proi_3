//
// Created by jakub on 29.05.19.
//

#include "Piece.h"


Piece::Piece(char n_colour, array<int, 2> n_position){
    colour = n_colour;
    position = n_position;
    moved = false;
}
array<int, 2> Piece::getPosition(){
    return position;
}
char Piece::getColour(){
    return colour;
}
char Piece::getSymbol(){
    return symbol;
}

void Piece::push(array<int, 2> where){
    position = where;
}
void Piece::setMoved(){
    moved = true;
}

vector<Piece*> Piece::attacked(Board p){
    vector<Piece*> attacking = p.getPieces();
    for(vector<Piece*>::iterator i = attacking.begin(); i < attacking.end();)
    {
        bool removed = false;
        if((*i)->getColour() == colour)
        {
            attacking.erase(i);
            removed = true;
        }
        else
        {
            vector<Move> moves = (*i)->moves(p);
            bool attack = false;
            for(vector<Move>::iterator j = moves.begin(); j != moves.end(); ++j)
                if((*j).getWhere() == position)
                    attack = true;
            if(!attack)
            {
                attacking.erase(i);
                removed = true;
            }
        }
        if(!removed)
            ++i;
    }
    return attacking;
}