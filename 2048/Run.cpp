#include "Assets\Headers\Game.h"

int main() {
    std::string MODE;
    size_t board_size; 

    do
    {
        std::cout << "Select game mode - NORMAL or INSANE mode only(Type EXIT to close the program): ";
        do
        {
            std::cin >> MODE;
        } while (MODE != "NORMAL" && MODE != "INSANE" && MODE != "EXIT");
        if(MODE == "EXIT") {
            break;
        }
        std::cout << std::endl;
        std::cout << "Import game board size(minimum length - 4): "; 
        do
        {
            std::cin >> board_size;
        } while (board_size < 4);
        std::cout << std::endl;
        
        Game game(board_size);
        game.Start(MODE);
    } while (1);

    std::cout << "Exiting 2048.Thank you for playing!" << std::endl;
    return 0;
}