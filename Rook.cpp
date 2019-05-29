//
// Created by jakub on 29.05.19.
//

#include "Rook.h"

Rook::Rook(char n_colour, array<int,2> n_position): Piece(n_colour, n_position){
    if(n_colour == 'w')
        Piece::symbol = 'R';
    else if(n_colour == 'b')
        Piece::symbol = 'r';
}
vector<Move> Rook::moves(Board p){
    vector<Move> moves;
    array<int, 2> position = this->getPosition();
    position[0] += 1;
    while(p.doesItFit(position) && !p.whoStands(position))
    {
        moves.push_back(Move(this, position));
        position[0] += 1;
    }
    if(p.doesItFit(position) && p.whoStands(position)->getColour() != this->getColour())
        moves.push_back(Move(this, position));

    position = this->getPosition();
    position[0] -= 1;
    while(p.doesItFit(position) && !p.whoStands(position))
    {
        moves.push_back(Move(this, position));
        position[0] -= 1;
    }
    if(p.doesItFit(position) && p.whoStands(position)->getColour() != this->getColour())
        moves.push_back(Move(this, position));

    position = this->getPosition();
    position[1] += 1;
    while(p.doesItFit(position) && !p.whoStands(position))
    {
        moves.push_back(Move(this, position));
        position[1] += 1;
    }
    if(p.doesItFit(position) && p.whoStands(position)->getColour() != this->getColour())
        moves.push_back(Move(this, position));

    position = this->getPosition();
    position[1] -= 1;
    while(p.doesItFit(position) && !p.whoStands(position))
    {
        moves.push_back(Move(this, position));
        position[1] -= 1;
    }
    if(p.doesItFit(position) && p.whoStands(position)->getColour() != this->getColour())
        moves.push_back(Move(this, position));
    return moves;
}