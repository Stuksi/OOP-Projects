#include "..\Headers\Pieces_H\Rook.h"

Rook::Rook (size_t _pos_x, size_t _pos_y, size_t _side) : Piece(_pos_x, _pos_y, _side) {}

bool Rook::can_move(size_t move_x, size_t move_y, Piece* board[8][8]) {
    if(move_x != pos_x && move_y == pos_y) {
        for (size_t i = std::min(move_x, pos_x); i < std::max(move_x, pos_x); i++)
        {
            if(board[move_y][i] != nullptr) {
                return false;
            }
        }
        return true;
    } else if(move_x == pos_x && move_y != pos_y) {
        for (size_t i = std::min(move_y, pos_y); i < std::max(move_y, pos_y); i++)
        {
            if(board[i][move_x] != nullptr) {
                return false;
            }
        }
        return true;
    }
    return false;
}

void Rook::print_piece() {
    if(side == 0) {
        std::cout << 'R';
    } else {
        std::cout << 'r';
    }
}