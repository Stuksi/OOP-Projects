#include "Headers\Board.h"
#include "Headers\Pieces_H\Pawn.h"
#include "Headers\Pieces_H\Bishop.h"
#include "Headers\Pieces_H\King.h"
#include "Headers\Pieces_H\Queen.h"
#include "Headers\Pieces_H\Knight.h"
#include "Headers\Pieces_H\Rook.h"

Board::Board() {
    for (size_t i = 2; i < 6; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            board[i][j] = nullptr;
        }
    }

    board[0][0] = new Rook(0, 0, 1);
    board[0][1] = new Knight(0, 1, 1);
    board[0][2] = new Bishop(0, 2, 1);
    board[0][3] = new Queen(0, 3, 1);
    board[0][4] = new King(0, 4, 1);
    board[0][5] = new Bishop(0, 5, 1);
    board[0][6] = new Knight(0, 6, 1);
    board[0][7] = new Rook(0, 7, 1);

    board[7][0] = new Rook(7, 0, 0);
    board[7][1] = new Knight(7, 1, 0);
    board[7][2] = new Bishop(7, 2, 0);
    board[7][3] = new Queen(7, 3, 0);
    board[7][4] = new King(7, 4, 0);
    board[7][5] = new Bishop(7, 5, 0);
    board[7][6] = new Knight(7, 6, 0);
    board[7][7] = new Rook(7, 7, 0);
    
    for (size_t i = 0; i < 8; i++)
    {
        board[1][i] = new Pawn(i, 1, 1);
        board[6][i] = new Pawn(i, 6, 0);
    }
    
}

Board::~Board() {
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            delete board[i][j]; 
        }
    }
}

void Board::print_board() {
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if(board[i][j] != nullptr) {
                board[i][j]->print_piece();
            } else {
                std::cout << "#";
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Board::move_piece(size_t current_x, size_t current_y, size_t move_x, size_t move_y) {
    if(board[current_y][current_x] != nullptr && board[current_y][current_x]->can_move(move_x, move_y, board)) {
        Piece* swap = board[current_y][current_x];
        board[current_y][current_x] = board[move_y][move_x];
        board[move_y][move_x] = swap;
        return;
    }
    std::cout << "Can't move the piece there!" << std::endl;
}
