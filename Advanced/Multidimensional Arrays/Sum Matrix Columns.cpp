#include <iostream>
#include <sstream>


int main() {
    int rows, columns;
    std::cin >> rows >> columns;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[columns];
    }


    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            std::cin >> matrix[row][col];
        }
    }

    std::stringstream resultStream{};
    for (int col = 0; col < columns; ++col) {
        int currentSum = 0;

        for (int row = 0; row < rows; ++row)
            currentSum += matrix[row][col];

        resultStream << currentSum << '\n';
    }

    std::cout << resultStream.str() << std::endl;


    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
