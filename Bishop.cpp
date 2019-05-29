//
// Created by jakub on 29.05.19.
//

#include "Bishop.h"



Bishop::Bishop(char n_colour, array<int,2> n_position): Piece(n_colour, n_position){
    if(n_colour == 'w')
        Piece::symbol = 'B';
    else if(n_colour == 'b')
        Piece::symbol = 'b';
}
vector<Move> Bishop::moves(Board p){
    vector<Move> moves;
    array<int, 2> position = this->getPosition();
    position[0] += 1;
    position[1] += 1;
    while(p.doesItFit(position) && !p.whoStands(position))
    {
        moves.push_back(Move(this, position));
        position[0] += 1;
        position[1] += 1;
    }
    if(p.doesItFit(position) && p.whoStands(position)->getColour() != this->getColour())
        moves.push_back(Move(this, position));

    position = this->getPosition();
    position[0] -= 1;
    position[1] += 1;
    while(p.doesItFit(position) && !p.whoStands(position))
    {
        moves.push_back(Move(this, position));
        position[0] -= 1;
        position[1] += 1;
    }
    if(p.doesItFit(position) && p.whoStands(position)->getColour() != this->getColour())
        moves.push_back(Move(this, position));

    position = this->getPosition();
    position[0] += 1;
    position[1] -= 1;
    while(p.doesItFit(position) && !p.whoStands(position))
    {
        moves.push_back(Move(this, position));
        position[0] += 1;
        position[1] -= 1;
    }
    if(p.doesItFit(position) && p.whoStands(position)->getColour() != this->getColour())
        moves.push_back(Move(this, position));

    position = this->getPosition();
    position[0] -= 1;
    position[1] -= 1;
    while(p.doesItFit(position) && !p.whoStands(position))
    {
        moves.push_back(Move(this, position));
        position[0] -= 1;
        position[1] -= 1;
    }
    if(p.doesItFit(position) && p.whoStands(position)->getColour() != this->getColour())
        moves.push_back(Move(this, position));
    return moves;
}