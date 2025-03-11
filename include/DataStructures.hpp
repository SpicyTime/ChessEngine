#pragma once
#include <functional>
#include <iostream>
struct Vector2{
    int x;
    int y;
    Vector2();
    Vector2(const int, const int);
};

//Hashes
namespace std{
    template<>
    struct hash<Vector2>  {
        size_t operator()(const Vector2& v) const{
            size_t h1 = hash<int>{}(v.x);
            size_t h2 = hash<int>{}(v.y);
            return h1 ^ (h2 << 1);
        }
    };
}

std::ostream& operator<<(std::ostream& , const Vector2& );
bool operator ==(const Vector2& , const Vector2& );
