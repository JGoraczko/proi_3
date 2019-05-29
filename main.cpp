#include <vector>
#include <array>
#include <iostream>
#include "Move.h"
#include "Board.h"
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "diplay.h"


using namespace std;



int main(int argc, char** argv) {
    Board b({8, 8});
    Knight knight('w', {0, 0});
    b.add(&knight);
    Move m(&knight, {2, 1});
    b.makeMove(m);
    Queen q('b', {0, 4});
    b.add(&q);
    cout<<b;
}