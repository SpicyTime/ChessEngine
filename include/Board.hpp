#pragma  once
#include "DataStructures.hpp"
#include "Piece.hpp"
#include <iostream>
#include <unordered_map>
#include <json/json.h>
#include <fstream>

class Board{
    private:
        void remove_piece(const Vector2);
        std::unordered_map<Vector2, Piece> load_board();
        void print_board();
        std::unordered_map<Vector2, Piece> board;
    public:
        void take_piece(const Vector2);
        void move_piece(const Piece piece, const Vector2 move_position);
        void init_board_pieces();

};
