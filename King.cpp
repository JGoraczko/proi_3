//
// Created by jakub on 29.05.19.
//

#include "King.h"



King::King(char n_kolor, array<int,2> n_pozycja): Piece(n_kolor, n_pozycja){
    if(n_kolor == 'w')
        Piece::symbol = 'K';
    else if(n_kolor == 'b')
        Piece::symbol = 'k';
}
vector<Move> King::moves(Board p){
    vector<Move> moves;
    array<int, 2> position = this->getPosition();
    position[0] += 1;
    position[1] += 1;
    Piece* pom = p.whoStands(position);
    if(p.doesItFit(position) && ((pom == 0) || (pom->getColour() != this->getColour())))
        moves.push_back(Move(this, position));

    position = this->getPosition();
    position[0] += 1;
    position[1] -= 1;
    pom = p.whoStands(position);
    if(p.doesItFit(position) && ((pom == 0) || (pom->getColour() != this->getColour())))
        moves.push_back(Move(this, position));

    position = this->getPosition();
    position[0] -= 1;
    position[1] += 1;
    pom = p.whoStands(position);
    if(p.doesItFit(position) && ((pom == 0) || (pom->getColour() != this->getColour())))
        moves.push_back(Move(this, position));

    position = this->getPosition();
    position[0] -= 1;
    position[1] -= 1;
    pom = p.whoStands(position);
    if(p.doesItFit(position) && ((pom == 0) || (pom->getColour() != this->getColour())))
        moves.push_back(Move(this, position));

    position = this->getPosition();
    position[0] += 1;
    pom = p.whoStands(position);
    if(p.doesItFit(position) && ((pom == 0) || (pom->getColour() != this->getColour())))
        moves.push_back(Move(this, position));

    position = this->getPosition();
    position[0] -= 1;
    pom = p.whoStands(position);
    if(p.doesItFit(position) && ((pom == 0) || (pom->getColour() != this->getColour())))
        moves.push_back(Move(this, position));

    position = this->getPosition();
    position[1] += 1;
    pom = p.whoStands(position);
    if(p.doesItFit(position) && ((pom == 0) || (pom->getColour() != this->getColour())))
        moves.push_back(Move(this, position));

    position = this->getPosition();
    position[1] -= 1;
    pom = p.whoStands(position);
    if(p.doesItFit(position) && ((pom == 0) || (pom->getColour() != this->getColour())))
        moves.push_back(Move(this, position));
    return moves;
}