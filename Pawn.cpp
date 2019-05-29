//
// Created by jakub on 29.05.19.
//

#include "Pawn.h"



Pawn::Pawn(char n_kolor, array<int,2> n_pozycja): Piece(n_kolor, n_pozycja){
    if(n_kolor == 'w')
        Piece::symbol = 'P';
    else if(n_kolor == 'b')
        Piece::symbol = 'p';
}
vector<Move> Pawn::moves(Board p){
    vector<Move> moves;
    array<int, 2> position = this->getPosition();
    if(this->getColour() == 'c')
    {
        position[0] += 1;
        if(p.doesItFit(position) && p.whoStands(position) == 0)
            moves.push_back(Move(this, position));
        position[1] += 1;
        if(p.doesItFit(position) && p.whoStands(position) != 0 && p.whoStands(position)->getColour() != this->getColour())
            moves.push_back(Move(this, position));
        position[1] -= 2;
        if(p.doesItFit(position) && p.whoStands(position) != 0 && p.whoStands(position)->getColour() != this->getColour())
            moves.push_back(Move(this, position));
    }
    else if(this->getColour() == 'b')
    {
        position = this->getPosition();
        position[0] -= 1;
        if(p.doesItFit(position) && p.whoStands(position) == 0)
            moves.push_back(Move(this, position));
        position[1] += 1;
        if(p.doesItFit(position) && p.whoStands(position) != 0 && p.whoStands(position)->getColour() != this->getColour())
            moves.push_back(Move(this, position));
        position[1] -= 2;
        if(p.doesItFit(position) && p.whoStands(position) != 0 && p.whoStands(position)->getColour() != this->getColour())
            moves.push_back(Move(this, position));
    }
    if(!moved)
    {
        if(this->getColour() == 'c')
        {
            position = this->getPosition();
            position[0] += 2;
            if(p.doesItFit(position) && p.whoStands(position) == 0)
                moves.push_back(Move(this, position));
        }
        else if(this->getColour() == 'b')
        {
            position = this->getPosition();
            position[0] -= 2;
            if(p.doesItFit(position) && p.whoStands(position) == 0)
                moves.push_back(Move(this, position));
        }
    }
    return moves;
}
