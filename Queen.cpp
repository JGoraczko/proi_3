//
// Created by jakub on 29.05.19.
//

#include "Queen.h"



Queen::Queen(char n_kolor, array<int,2> n_pozycja): Piece(n_kolor, n_pozycja){
    if(n_kolor == 'w')
        Piece::symbol = 'Q';
    else if(n_kolor == 'b')
        Piece::symbol = 'q';

}
vector<Move> Queen::moves(Board p){
    vector<Move> moves;
    array<int, 2> position1 = this->getPosition();
    position1[0] += 1;
    position1[1] += 1;
    while(p.doesItFit(position1) && !p.whoStands(position1))
    {
        moves.push_back(Move(this, position1));
        position1[0] += 1;
        position1[1] += 1;
    }
    if(p.doesItFit(position1) && p.whoStands(position1)->getColour() != this->getColour())
        moves.push_back(Move(this, position1));

    position1 = this->getPosition();
    position1[0] -= 1;
    position1[1] += 1;
    while(p.doesItFit(position1) && !p.whoStands(position1))
    {
        moves.push_back(Move(this, position1));
        position1[0] -= 1;
        position1[1] += 1;
    }
    if(p.doesItFit(position1) && p.whoStands(position1)->getColour() != this->getColour())
        moves.push_back(Move(this, position1));

    position1 = this->getPosition();
    position1[0] += 1;
    position1[1] -= 1;
    while(p.doesItFit(position1) && !p.whoStands(position1))
    {
        moves.push_back(Move(this, position1));
        position1[0] += 1;
        position1[1] -= 1;
    }
    if(p.doesItFit(position1) && p.whoStands(position1)->getColour() != this->getColour())
        moves.push_back(Move(this, position1));

    position1 = this->getPosition();
    position1[0] -= 1;
    position1[1] -= 1;
    while(p.doesItFit(position1) && !p.whoStands(position1))
    {
        moves.push_back(Move(this, position1));
        position1[0] -= 1;
        position1[1] -= 1;
    }
    if(p.doesItFit(position1) && p.whoStands(position1)->getColour() != this->getColour())
        moves.push_back(Move(this, position1));

    position1 = this->getPosition();
    position1[0] += 1;
    while(p.doesItFit(position1) && !p.whoStands(position1))
    {
        moves.push_back(Move(this, position1));
        position1[0] += 1;
    }
    if(p.doesItFit(position1) && p.whoStands(position1)->getColour() != this->getColour())
        moves.push_back(Move(this, position1));

    position1 = this->getPosition();
    position1[0] -= 1;
    while(p.doesItFit(position1) && !p.whoStands(position1))
    {
        moves.push_back(Move(this, position1));
        position1[0] -= 1;
    }
    if(p.doesItFit(position1) && p.whoStands(position1)->getColour() != this->getColour())
        moves.push_back(Move(this, position1));

    position1 = this->getPosition();
    position1[1] += 1;
    while(p.doesItFit(position1) && !p.whoStands(position1))
    {
        moves.push_back(Move(this, position1));
        position1[1] += 1;
    }
    if(p.doesItFit(position1) && p.whoStands(position1)->getColour() != this->getColour())
        moves.push_back(Move(this, position1));

    position1 = this->getPosition();
    position1[1] -= 1;
    while(p.doesItFit(position1) && !p.whoStands(position1))
    {
        moves.push_back(Move(this, position1));
        position1[1] -= 1;
    }
    if(p.doesItFit(position1) && p.whoStands(position1)->getColour() != this->getColour())
        moves.push_back(Move(this, position1));
    return moves;
}