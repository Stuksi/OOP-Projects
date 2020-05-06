#include "Headers\Game.h"
#include "Headers\Board.h"

#include <string>
#include <vector>
#include <iostream>

void Game::skipEmptySpaces(std::string& string, size_t &k) {
    while (string[k] == ' ')
    {
        if(k >= string.length()){
            return;
        }
        k++;
    }
}

void Game::Start() {
    Board board;

    // std::string user_input, command, temp;
    // std::vector<std::string> input_values;
    // size_t k;

    // do
    // {
    //     command = "";
    //     temp = "";
    //     input_values.clear();
    //     k = 0;

    //     std::getline(std::cin, user_input);

    //     skipEmptySpaces(user_input, k);
    //     while (user_input[k] != ' ' && user_input[k] != '\0')
    //     {
    //         command += user_input[k];
    //         k++;
    //     }
    //     skipEmptySpaces(user_input, k);
    //     while (user_input[k] != ' ' && user_input[k] != '\0')
    //     {
    //         if(user_input[k] != ' ' && user_input[k] != '\0') {
    //             temp += user_input[k];
    //             k++;
    //         }
    //         if(user_input[k] == ' ' || user_input[k] == '\0') {
    //             input_values.push_back(temp);
    //             temp = "";
    //             skipEmptySpaces(user_input, k);
    //         }
    //     }




    board.print_board();








    // } while (!game_over());
}