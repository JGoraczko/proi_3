//
// Created by jakub on 29.05.19.
//

#ifndef PROI_3_BOARD_H
#define PROI_3_BOARD_H
#include <vector>
#include <array>
#include "Move.h"


using namespace std;

class Piece;


class Board{
    array<int, 2> size;
    vector<Piece*> pieces;
public:
    Board(array<int, 2>);
    Board(Board&) = default;
    ~Board() = default;
    vector<Piece*> getPieces();
    array<int, 2> getSize();
    void add(Piece*);
    void remove(Piece*);
    bool doesItFit(array<int, 2>); //sprawdza czy pole nie jest poza szachownicą
    Piece* whoStands(array<int, 2>);   //wskazuje bierke stojącą na danym polu, albo pusty wskażnik, gdy pole jest puste
    void makeMove(Move);
};

#endif //PROI_3_BOARD_H
