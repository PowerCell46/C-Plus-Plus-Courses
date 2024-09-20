#include <algorithm>
#include <iostream>
#include <ctime>


void drawBoard(char *spaces);

void playerMove(char *spaces, char player);

void computerMove(char *spaces, char computer);

bool checkWinner(char *spaces, char player, char computer);

bool checkTie(char *spaces);


int main() {
    char spaces[9];
    std::fill(spaces, spaces + 9, ' ');
    char player = 'X';
    char computer = 'O';
    bool isRunning = true;

    drawBoard(spaces);

    while (isRunning) {
        playerMove(spaces, player);
        drawBoard(spaces);
        
        if (checkWinner(spaces, player, computer) || checkTie(spaces)) {
            isRunning = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
      
        if (checkWinner(spaces, player, computer) || checkTie(spaces)) {
            isRunning = false;
            break;
        }
    }

    return 0;
}

void drawBoard(char *spaces) {
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << std::endl;
}

void playerMove(char *spaces, char player) {
    int number;

    do {
        std::cout << "Enter a position: " << std::endl;
        std::cin >> number;
        number--;

        if (spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }

    } while (!number > 0 || !number < 8);
}

void computerMove(char *spaces, char computer) {
    int number;
    srand(time(0));

    while (true) {
        number = rand() % 9;

        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer) {
    if ( // player check
        // horizontals
        spaces[0] == player && spaces[1] == player && spaces[2] == player ||
        spaces[3] == player && spaces[4] == player && spaces[5] == player ||
        spaces[6] == player && spaces[7] == player && spaces[8] == player ||
        // verticals
        spaces[0] == player && spaces[3] == player && spaces[6] == player ||
        spaces[1] == player && spaces[4] == player && spaces[7] == player ||
        spaces[2] == player && spaces[5] == player && spaces[8] == player ||
        // diagonals
        spaces[0] == player && spaces[4] == player && spaces[8] == player ||
        spaces[2] == player && spaces[4] == player && spaces[6] == player
    ) {
        std::cout << "You win!";
        return true;
    }

    if ( // computer check
        // horizontals
        spaces[0] == computer && spaces[1] == computer && spaces[2] == computer ||
        spaces[3] == computer && spaces[4] == computer && spaces[5] == computer ||
        spaces[6] == computer && spaces[7] == computer && spaces[8] == computer ||
        // verticals
        spaces[0] == computer && spaces[3] == computer && spaces[6] == computer ||
        spaces[1] == computer && spaces[4] == computer && spaces[7] == computer ||
        spaces[2] == computer && spaces[5] == computer && spaces[8] == computer ||
        // diagonals
        spaces[0] == computer && spaces[4] == computer && spaces[8] == computer ||
        spaces[2] == computer && spaces[4] == computer && spaces[6] == computer
    ) {
        std::cout << "You lose!";
        return true;
    }

    return false;
}

bool checkTie(char *spaces) {
    if (
        spaces[0] != ' ' &&
        spaces[1] != ' ' &&
        spaces[2] != ' ' &&
        spaces[3] != ' ' &&
        spaces[4] != ' ' &&
        spaces[5] != ' ' &&
        spaces[6] != ' ' &&
        spaces[7] != ' ' &&
        spaces[8] != ' '
    ) return true;

    return false;
}
