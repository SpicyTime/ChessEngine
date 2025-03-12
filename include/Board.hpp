#pragma  once
#include "DataStructures.hpp"
#include "Piece.hpp"
#include <iostream>
#include <unordered_map>
#include <json/json.h>
#include <fstream>

class Board{
    private:
        void removePiece(const Vector2);
        void move(int& , const int);
         
        std::unordered_map<Vector2, Piece> loadBoard();
        void printBoard();
        std::unordered_map<Vector2, Piece> board;
        bool inBounds(const Vector2);
        const int board_length = 8;
        const int board_height = 8;
    public:

        void take_piece(const Vector2);
        void move_piece(const Piece piece, const Vector2 move_position);
        void initBoardPieces();
        //std::vector<Vector2> valid_move_positions(const Piece p);
};
