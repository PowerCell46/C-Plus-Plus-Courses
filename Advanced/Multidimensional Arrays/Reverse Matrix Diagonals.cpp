#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#define EMPTY_INT_VAL -1'000'000


void printNewMatrix(std::vector<std::vector<int> > &);


int main() {
    int rowsNumber, columnsNumber;
    std::cin >> rowsNumber >> columnsNumber;

    int **matrix = new int *[rowsNumber];
    for (int i = 0; i < rowsNumber; ++i)
        matrix[i] = new int[columnsNumber];


    for (int row = 0; row < rowsNumber; ++row)
        for (int col = 0; col < columnsNumber; ++col)
            std::cin >> matrix[row][col];


    std::vector<std::vector<int> > numbersMatrix;

    for (int index = 0; index < rowsNumber; ++index) {
        std::vector<int> currentDiagonalVector;

        for (int xedni = 0; xedni < rowsNumber - index; ++xedni)
            currentDiagonalVector.push_back(matrix[xedni][index]);

        for (int xedni = index + 1; xedni < columnsNumber; ++xedni)
            currentDiagonalVector.push_back(matrix[rowsNumber - 1 - index][xedni]);

        std::reverse(currentDiagonalVector.begin(), currentDiagonalVector.end());

        numbersMatrix.push_back(currentDiagonalVector);
    }

    printNewMatrix(numbersMatrix);

    for (int i = 0; i < rowsNumber; ++i)
        delete matrix[i];
    delete[] matrix;

    return 0;
}


void printNewMatrix(std::vector<std::vector<int> > &matrixVector) {
    int **matrix = new int *[matrixVector.at(0).size()];
    for (int i = 0; i < matrixVector.at(0).size(); ++i) {
        matrix[i] = new int[matrixVector.size()]{};
        for (int j = 0; j < matrixVector.size(); ++j)
            matrix[i][j] = EMPTY_INT_VAL;
    }

    int padding = 0;
    for (int index = 0; index < matrixVector.size(); ++index) {

        for (int xedni = 0; xedni < matrixVector.at(index).size(); ++xedni) {
            // if (xedni < padding || xedni >= matrixVector.at(index).size() - padding)
            //     matrix[xedni][index] = -1;
            // else
            matrix[xedni + padding][index] = matrixVector.at(index).at(xedni);
        }

        padding++;
    }

    for (int row = 0; row < matrixVector.at(0).size(); ++row) {
        for (int col = 0; col < matrixVector.size(); ++col) {
            if (matrix[row][col] == EMPTY_INT_VAL)
                std::cout << "  ";
            else
                std::cout << matrix[row][col] << ' ';
        }
        std::cout << std::endl;
    }


    for (int i = 0; i < matrixVector.at(0).size(); ++i)
        delete[] matrix[i];
    delete[] matrix;
}

// 10 11 13 16 18
// 17 14 12
// 15

// 10
// 11 12
// 13 14 15
// 16 17
// 18
