#include "Headers\Game.h"

void Game::skipEmptySpaces(std::string& string, size_t &k) {
    while (string[k] == ' ')
    {
        if(k >= string.length()){
            return;
        }
        k++;
    }
}

bool Game::correct_command(std::vector<std::string> input_values) {
    if(input_values.size() != 2) {
        return false;
    }
    for (size_t i = 0; i < 2; i++)
    {
        if(input_values[i][0] < 'a' || input_values[i][0] > 'h'
        || input_values[i][1] < '1' || input_values[i][1] > '8') {
            return false;
        }
    }
    return true;
}

bool Game::game_over() {
    return false;
}



void Game::Start() {
    Board board;

    std::string user_input, command, temp;
    std::vector<std::string> input_values;
    size_t k;

    do
    {
        command = "";
        temp = "";
        input_values.clear();
        k = 0;

        std::cout << std::endl;
        board.print_board();

        std::getline(std::cin, user_input);

        skipEmptySpaces(user_input, k);
        while (user_input[k] != ' ' && user_input[k] != '\0')
        {
            command += user_input[k];
            k++;
        }
        skipEmptySpaces(user_input, k);
        while (user_input[k] != ' ' && user_input[k] != '\0')
        {
            if(user_input[k] != ' ' && user_input[k] != '\0') {
                temp += user_input[k];
                k++;
            }
            if(user_input[k] == ' ' || user_input[k] == '\0') {
                input_values.push_back(temp);
                temp = "";
                skipEmptySpaces(user_input, k);
            }
        }

        if(command == "move") {
            if(correct_command(input_values)) {
                board.move_piece(input_values[0][0]-'a', 7-(input_values[0][1]-'1'), input_values[1][0]-'a', 7-(input_values[1][1]-'1'));
            } else {
                std::cout << "Wrong use of command!" << std::endl;
            }
        }

    } while (!game_over());
}