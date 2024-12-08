#include <iostream>
#include <sstream>


int main() {
    int matrixRows, matrixColumns;
    std::cin >> matrixRows >> matrixColumns;

    // init the matrix
    int** matrix = new int*[matrixRows];
    for (int i = 0; i < matrixRows; ++i)
        matrix[i] = new int[matrixColumns];

    // fill the matrix
    for (int row = 0; row < matrixRows; ++row)
        for (int col = 0; col < matrixColumns; ++col)
            std::cin >> matrix[row][col];


    int sum = -1;
    std::string result{};
    //iterate through the matrix and find the 3x3 with the biggest Sum
    for (int row = 0; row < matrixRows; ++row) {
        for (int col = 0; col < matrixColumns; ++col) {
            std::stringstream currentLineStream{};

            //--------------------------------------------------
            int currentIndexSum = matrix[row][col];
            currentLineStream << matrix[row][col] << ' ';

            if (col + 1 < matrixColumns) {
                currentIndexSum += matrix[row][col + 1];
                currentLineStream << matrix[row][col + 1] << ' ';
            }
            if (col + 2 < matrixColumns) {
                currentIndexSum += matrix[row][col + 2];
                currentLineStream << matrix[row][col + 2];
            }

            //--------------------------------------------------
            if (row + 1 < matrixRows) {
                currentIndexSum += matrix[row + 1][col];
                currentLineStream << '\n' << matrix[row + 1][col] << ' ';
            }
            if (row + 1 < matrixRows && col + 1 < matrixColumns) {
                currentIndexSum += matrix[row + 1][col + 1];
                currentLineStream << matrix[row + 1][col + 1] << ' ';
            }
            if (row + 1 < matrixRows && col + 2 < matrixColumns) {
                currentIndexSum += matrix[row + 1][col + 2];
                currentLineStream << matrix[row + 1][col + 2];
            }

            //--------------------------------------------------
            if (row + 2 < matrixRows) {
                currentIndexSum += matrix[row + 2][col];
                currentLineStream << '\n' << matrix[row + 2][col] << ' ';
            }
            if (row + 2 < matrixRows && col + 1 < matrixColumns) {
                currentIndexSum += matrix[row + 2][col + 1];
                currentLineStream << matrix[row + 2][col + 1] << ' ';
            }
            if (row + 2 < matrixRows && col + 2 < matrixColumns) {
                currentIndexSum += matrix[row + 2][col + 2];
                currentLineStream << matrix[row + 2][col + 2] << ' ';
            }

            //--------------------------------------------------
            if (currentIndexSum > sum) {
                sum = currentIndexSum;
                std::stringstream finalCurrentLineStream{};
                finalCurrentLineStream << "Sum = " << currentIndexSum << '\n' << currentLineStream.str();
                result = finalCurrentLineStream.str();
            }
        }
    }

    // print the result
    std::cout << result << std::endl;

    // cleanup
    for (int i = 0; i < matrixRows; ++i)
        delete[] matrix[i];
    delete[] matrix;


    return 0;
}
