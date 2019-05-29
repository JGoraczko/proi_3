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
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("moving rook"){
    Board b({8, 8});
    Rook r('w', {1, 2});
    b.add(&r);
    REQUIRE(b.getPieces()[0] == &r);
    REQUIRE(b.whoStands({1, 2}) == &r);
    REQUIRE(r.moves(b).size() == 14);
    Move m(&r, {2, 2});
    b.makeMove(m);
    REQUIRE(b.getPieces()[0] == &r);
    REQUIRE(b.whoStands({2, 2}) == &r);
    REQUIRE(r.moves(b).size() == 14);
    Queen q('b', {7, 2});
    b.add(&q);
    REQUIRE(q.attacked(b)[0] == &r);
    REQUIRE(r.attacked(b)[0] == &q);
}

TEST_CASE("moving bishop"){
    Board b({8, 8});
    Bishop bishop('w', {1, 2});
    b.add(&bishop);
    REQUIRE(b.getPieces()[0] == &bishop);
    REQUIRE(b.whoStands({1, 2}) == &bishop);
    REQUIRE(bishop.moves(b).size() == 9);
    Move m(&bishop, {2, 3});
    b.makeMove(m);
    REQUIRE(b.getPieces()[0] == &bishop);
    REQUIRE(b.whoStands({2, 3}) == &bishop);
    REQUIRE(bishop.moves(b).size() == 11);
    Queen q('b', {2, 2});
    b.add(&q);
    REQUIRE(q.attacked(b).size() == 0);
    REQUIRE(bishop.attacked(b)[0] == &q);
}

TEST_CASE("moving pawn"){
    Board b({8, 8});
    Pawn pawn('w', {6, 2});
    b.add(&pawn);
    REQUIRE(b.getPieces()[0] == &pawn);
    REQUIRE(b.whoStands({6, 2}) == &pawn);
    REQUIRE(pawn.moves(b).size() == 2);
    Move m(&pawn, {5, 2});
    b.makeMove(m);
    REQUIRE(b.getPieces()[0] == &pawn);
    REQUIRE(b.whoStands({5, 2}) == &pawn);
    REQUIRE(pawn.moves(b).size() == 1);
    SECTION("adding queen to capture") {
        Queen q('b', {4, 1});
        b.add(&q);
        REQUIRE(pawn.moves(b).size() == 2);
    }
    SECTION("adding queen in the way") {
        Queen q('w', {4, 2});
        b.add(&q);
        REQUIRE(pawn.moves(b).size() == 0);
    }

}

TEST_CASE("moving king"){
    Board b({8, 8});
    King king('w', {0, 0});
    b.add(&king);
    REQUIRE(b.getPieces()[0] == &king);
    REQUIRE(b.whoStands({0, 0}) == &king);
    REQUIRE(king.moves(b).size() == 3);
    Move m(&king, {1, 1});
    b.makeMove(m);
    REQUIRE(b.getPieces()[0] == &king);
    REQUIRE(b.whoStands({1, 1}) == &king);
    REQUIRE(king.moves(b).size() == 8);
    Queen q('b', {0, 0});
    b.add(&q);
    REQUIRE(king.moves(b).size() == 8);
    REQUIRE(q.attacked(b)[0] == &king);
}

TEST_CASE("moving knight"){
    Board b({8, 8});
    Knight knight('w', {0, 0});
    b.add(&knight);
    REQUIRE(b.getPieces()[0] == &knight);
    REQUIRE(b.whoStands({0, 0}) == &knight);
    REQUIRE(knight.moves(b).size() == 2);
    Move m(&knight, {2, 1});
    b.makeMove(m);
    REQUIRE(b.getPieces()[0] == &knight);
    REQUIRE(b.whoStands({2, 1}) == &knight);
    REQUIRE(knight.moves(b).size() == 6);
    Queen q('b', {4, 0});
    b.add(&q);
    REQUIRE(knight.moves(b).size() == 6);
    REQUIRE(q.attacked(b)[0] == &knight);
}

TEST_CASE("moving queen"){
    Board b({8, 8});
    Queen queen('w', {0, 0});
    b.add(&queen);
    REQUIRE(b.getPieces()[0] == &queen);
    REQUIRE(b.whoStands({0, 0}) == &queen);
    REQUIRE(queen.moves(b).size() == 21);
    Move m(&queen, {2, 2});
    b.makeMove(m);
    REQUIRE(b.getPieces()[0] == &queen);
    REQUIRE(b.whoStands({2, 2}) == &queen);
    REQUIRE(queen.moves(b).size() == 25);
    King k('b', {0, 0});
    b.add(&k);
    REQUIRE(queen.moves(b).size() == 25);
    REQUIRE(k.attacked(b)[0] == &queen);
}