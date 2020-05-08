#include "..\Headers\Pieces_H\Pawn.h"

Pawn::Pawn(size_t _pos_x, size_t _pos_y, size_t _side) : Piece(_pos_x, _pos_y, _side) {}

bool Pawn::can_move (size_t move_x, size_t move_y, Piece* board[8][8]) {
    if(side == 0) {
        if(move_y == pos_y-1) {
            return move_x == pos_x && board[move_y][move_x] == nullptr
            || move_x == pos_x-1 && board[move_y][move_x]->get_side() == 1
            || move_x == pos_x+1 && board[move_y][move_x]->get_side() == 1;
        } else if(move_y == pos_y-2) {
            return pos_y == 6 && move_x == pos_x && board[move_y][move_x] == nullptr;
        }
    } else {
        if(move_y == pos_y+1) {
            return move_x == pos_x && board[move_y][move_x] == nullptr
            || move_x == pos_x-1 && board[move_y][move_x]->get_side() == 0
            || move_x == pos_x+1 && board[move_y][move_x]->get_side() == 0;
        } else if(move_y == pos_y+2) {
            return pos_y == 1 && move_x == pos_x && board[move_y][move_x] == nullptr;
        }
    }
    return false;
}

void Pawn::print_piece() {
    if(side == 0) {
        std::cout << 'P';
    } else {
        std::cout << 'p';
    }
}