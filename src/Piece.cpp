#include "Piece.hpp"
 
 
Piece::Piece(const std::string id, const bool color_id, const Vector2 position){
    assert(color_id == WHITE || color_id == BLACK && "Color is not valid");
    
    this->id = id;
    this->color_id = color_id;
    this->position = position;
}
Piece::Piece(){
    id = "";
    color_id = BLACK;
    position = Vector2(0, 0);
}
//Operator overloads
bool operator ==(const Piece other1, const Piece other2){
    return other1.color_id == other2.color_id && other1.id == other2.id && other1.position == other2.position;
}
std::ostream& operator << (std::ostream& os ,const Piece& piece){
    os << "Piece: " << piece.id << ", Color: " << piece.color_id << ", Position";
    return os;
}
