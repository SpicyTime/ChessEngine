#include "Board.hpp"
void Board::removePiece(const Vector2 position)
{
    std::unordered_map<Vector2, Piece> m;
    board.erase(position);
}
std::unordered_map<Vector2, Piece> Board::loadBoard()
{
    // Loads the json data from the file
    std::ifstream file("/workspaces/ChessEngine/config/ChessInitData.json");
    Json::Value json_data;
    file >> json_data;
    file.close();
    // converts the json data to pieces
    std::unordered_map<Vector2, Piece> loaded_board;
    for (const auto &key : json_data.getMemberNames())
    {
        for (const auto &piece : json_data[key])
        {
            std::string type_string = key;
            std::string color = piece[0].asString();
            int x = piece[1][0].asInt();
            int y = piece[1][1].asInt();

            
            Vector2 position = Vector2(x, y);
            Piece new_piece = Piece(charToPieceType(type_string[0]), charToColor(color[0]), position);
            loaded_board[position] = new_piece;
            // std::cout << new_piece;
        }
        // std::cout << '\n';
    }

    return loaded_board;
}

void Board::move(int &vpos, const int amount)
{
    vpos += amount;
}

void Board::printBoard()
{
    std::cout << "Printing Board";
    for (const auto &pair : board)
    {
        std::cout << pair.second << " " << pair.first << '\n';
    }
}
void Board::initBoardPieces()
{
    board = loadBoard();
}
void Board::move_piece(const Piece piece, const Vector2 move_position)
{
     
}
void Board::take_piece(const Vector2 position)
{
    removePiece(position);
}

bool Board::inBounds(const Vector2 position)
{
    // Checks the x axis
    if (position.x > board_length || position.y < 0)
    {
        return false;
    }
    // Checks the y axis
    if (position.y > board_height || position.y < 0)
    {
        return false;
    }
    return true;
}


