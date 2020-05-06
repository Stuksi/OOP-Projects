#include "Headers\Board.h"
#include "Headers\Pawn.h"

Board::Board() {
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            board[i][j] = new Tile(i, j, new Pawn(i, j, 0));   
        }
    }
}

void Board::print_board() {
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            board[i][j]->print_tile();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}