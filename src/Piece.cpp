#include "Piece.hpp"
 
 
Piece::Piece(const PieceType type, const Color color, const Vector2 position){
    
    this->type= type;
    this->color = color;
    this->position = position;
}
Piece::Piece(){
    type = PieceType::PAWN;
    color = BLACK;
    position = Vector2(0, 0);
}

Piece::~Piece()
{
    //std::cout  << " Is being destroyed";
}

//Operator overloads
bool operator ==(const Piece other1, const Piece other2){
    return other1.color == other2.color && other1.type == other2.type && other1.position == other2.position;
}
const char *pieceTypeToString(PieceType piece)
{
    switch (piece) {
        ENUM_TO_STRING_CASE(PieceType
        ::PAWN)
        ENUM_TO_STRING_CASE(PieceType
        ::ROOK)
        ENUM_TO_STRING_CASE(PieceType
        ::BISHOP)
        ENUM_TO_STRING_CASE(PieceType
        ::KNIGHT)
        ENUM_TO_STRING_CASE(PieceType
        ::QUEEN)
        ENUM_TO_STRING_CASE(PieceType
        ::KING)
        default: return "UNKNOWN";
    }
}
Color charToColor(char c)
{   
    switch(c){
        case 'W':
            return WHITE;
        default:
            return BLACK;
    }
}
PieceType charToPieceType(char c)
{
    switch(c){
        case 'R':
            return  ROOK;
        case 'B':
            return BISHOP;
        case 'N':
            return KNIGHT;
        case 'Q':
            return QUEEN;
        case 'K':
            return KING;
        default: 
            return PAWN;
    }
}
std::ostream &operator<<(std::ostream &os, const Piece &piece)
{
    os << "Piece: " << piece.type << ", Color: " << piece.color << ", Position";
    return os;
}
