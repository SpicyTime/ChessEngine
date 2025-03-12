#pragma once
#include "DataStructures.hpp"
#include <iostream>
#include <cassert>
#include <string>
#define ENUM_TO_STRING_CASE(x) case x: return #x;
//Enums
enum Color{
    WHITE = 0,
    BLACK = 1
};
enum PieceType{
    PAWN = 0,
    ROOK,
    BISHOP,
    KNIGHT,
    QUEEN,
    KING
};

//Structs
class  Piece{
    private:
        Vector2 position;
        PieceType
     type;
        Color color;
         
    public:
        //Constructors
        Piece(const PieceType
        , const Color, const Vector2);
        Piece();
        //Destructurs
        ~Piece();
        //Operator overloads
        friend std::ostream& operator << (std::ostream& ,const Piece&);
        friend bool operator ==(const Piece, const Piece);
};

const char* pieceTypeToString(PieceType);
PieceType charToPieceType(char);
Color charToColor(char);
 
 
 
