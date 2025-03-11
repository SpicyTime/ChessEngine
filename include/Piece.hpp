#pragma once
#include "DataStructures.hpp"
#include <iostream>
#include <cassert>
#include <string>
//Enums
enum COLOR{
    WHITE = true,
    BLACK = false
};
enum PIECETYPE{
    PAWN = 0,
    ROOK,
    BISHOP,
    KNIGHT,
    QUEEN,
    KING
};

//Structs
struct Piece{
    Vector2 position;
    std::string id;
    bool color_id;
    Piece(const std::string id  , const bool color_id  , const Vector2 position  );
    Piece();
};


//Operator overloads
std::ostream& operator << (std::ostream& ,const Piece&);
bool operator ==(const Piece, const Piece);
