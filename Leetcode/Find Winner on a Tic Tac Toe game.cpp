#include <iostream>
#include <vector>
#include <sstream>

using std::string;
using std::vector;


class Solution {
    static std::vector<std::vector<char>> initBoard() {
        std::vector<std::vector<char>> playingBoard(3);
        for (int i = 0; i < 3; ++i)
            playingBoard[i] = std::vector<char>{'-', '-', '-'};
        
        return playingBoard;
    }
    
    static bool checkForAWinner(const std::vector<std::vector<char>>& playingBoard, const char& currentPlayer) {
        const bool checkRows = (
            playingBoard[0][0] == currentPlayer && playingBoard[0][1] == currentPlayer && playingBoard[0][2] == currentPlayer ||
            playingBoard[1][0] == currentPlayer && playingBoard[1][1] == currentPlayer && playingBoard[1][2] == currentPlayer ||
            playingBoard[2][0] == currentPlayer && playingBoard[2][1] == currentPlayer && playingBoard[2][2] == currentPlayer
        );

        const bool checkColumns = (
            playingBoard[0][0] == currentPlayer && playingBoard[1][0] == currentPlayer && playingBoard[2][0] == currentPlayer ||
            playingBoard[0][1] == currentPlayer && playingBoard[1][1] == currentPlayer && playingBoard[2][1] == currentPlayer ||
            playingBoard[0][2] == currentPlayer && playingBoard[1][2] == currentPlayer && playingBoard[2][2] == currentPlayer
        );

        const bool checkDiagonals = (
            playingBoard[0][0] == currentPlayer && playingBoard[1][1] == currentPlayer && playingBoard[2][2] == currentPlayer ||
            playingBoard[2][0] == currentPlayer && playingBoard[1][1] == currentPlayer && playingBoard[0][2] == currentPlayer
        );

        return checkRows || checkColumns || checkDiagonals;
    }
    
public:
    string tictactoe(vector<vector<int>>& moves) {
        std::vector<std::vector<char>> playingBoard = initBoard();

        int xMoves{}, yMoves{};

        for (auto iter = moves.begin(); iter != moves.end(); ++iter) {
            const bool xIsCurrentPlayer = !((iter - moves.begin()) & 1);

            playingBoard[(*iter)[0]][(*iter)[1]] = xIsCurrentPlayer ? 'X' : 'O';

            xMoves += xIsCurrentPlayer;
            yMoves += !xIsCurrentPlayer;
            
            if ((xMoves >= 3 || yMoves >= 3) && checkForAWinner(playingBoard, xIsCurrentPlayer ? 'X' : 'O'))
                return xIsCurrentPlayer ? "A" : "B";

            if (xMoves + yMoves == 9)
                return "Draw";
        }

        return "Pending";
    }
};


int main() {
    Solution s;

    std::vector<std::vector<int>> data = {{0,0},{2,0},{1,1},{2,1},{2,2}};
    // std::vector<std::vector<int>> data = {{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
    // std::vector<std::vector<int>> data = {{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};

    std::cout << s.tictactoe(data);

    return 0;
}
