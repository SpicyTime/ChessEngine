#include "DataStructures.hpp"

//Data structures
Vector2::Vector2(const int x, const int y){
    this->x = x;
    this->y = y;
}
Vector2::Vector2(){
    x = 0;
    y = 0;
}


//Operator overloads

//Vector2 overloads
bool operator ==(const Vector2& other1, const Vector2& other2){
    return other1.x == other2.x && other1.y == other2.y;
}
std::ostream& operator<<(std::ostream& os, const Vector2& v) {
    os << "Vector2: (" << v.x << ", " << v.y << ")";
    return os;
}