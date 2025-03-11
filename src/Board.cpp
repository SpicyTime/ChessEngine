#include "Board.hpp"
void Board::remove_piece(const Vector2 position){
    std::unordered_map<Vector2, Piece> m;
    board.erase(position);
}   
std::unordered_map<Vector2, Piece> Board::load_board(){
    std::ifstream file("ChessInitData.json");
    Json::Value json_data;
    file >> json_data;
    file.close();
    //std::unordered_map<std::string, std::vector<std::pair<std::string, std::pair<int, int>>>> chess_pieces;
    std::unordered_map<Vector2, Piece> loaded_board;
    for(const auto& key : json_data.getMemberNames()){
        for(const auto& piece : json_data[key]){
            std::string color = piece[0].asString();
            std::string id = key;
            int x = piece[1][0].asInt();
            int y = piece[1][1].asInt();
            bool color_id = BLACK;
            if(color == "W"){
                color_id = WHITE;
            }
            Vector2 position = Vector2(x, y);
            Piece new_piece = Piece(id, color_id, position);
            loaded_board[position] = new_piece;
        }
    }
    
    return  loaded_board;
}
void Board::print_board(){
    for(const auto& [pos, piece] : board){
        std::cout << pos << piece << '\n';
    }
}
void Board::init_board_pieces(){
load_board();
print_board();
}
void Board::move_piece(const Piece piece, const Vector2 move_position){
if(board[move_position].color_id != piece.color_id){
    take_piece(move_position);
}
}
void Board::take_piece(const Vector2 position){
remove_piece(position);
}
     
