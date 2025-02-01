#include <iostream>
#include <sstream>

#define MINED '!'
#define EMPTY '.'


int main() {
    int rows, columns;
    std::cin >> rows >> columns;

    // Init Matrix
    char **matrix = new char *[rows];

    for (int i = 0; i < rows; ++i) {
        // Init Row
        matrix[i] = new char[columns];

        std::string currentLine;
        std::cin >> currentLine;

        // Read Row
        for (int j = 0; j < columns; ++j)
            matrix[i][j] = currentLine[j];
    }

    std::stringstream resultMatrixStream{};

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            // Current Row
            int numberOfMinedFields = matrix[i][j] == MINED;
            if (j > 0)
                numberOfMinedFields += matrix[i][j - 1] == MINED;
            if (j < columns - 1)
                numberOfMinedFields += matrix[i][j + 1] == MINED;

            // Previous Row
            if (i > 0) {
                numberOfMinedFields += matrix[i - 1][j] == MINED;
                if (j > 0)
                    numberOfMinedFields += matrix[i - 1][j - 1] == MINED;
                if (j < columns - 1)
                    numberOfMinedFields += matrix[i - 1][j + 1] == MINED;
            }

            // Next Row
            if (i < rows - 1) {
                numberOfMinedFields += matrix[i + 1][j] == MINED;
                if (j > 0)
                    numberOfMinedFields += matrix[i + 1][j - 1] == MINED;
                if (j < columns - 1)
                    numberOfMinedFields += matrix[i + 1][j + 1] == MINED;
            }
            resultMatrixStream << numberOfMinedFields;
        }
        resultMatrixStream << '\n';
    }

    std::cout << resultMatrixStream.str();

    // Clean up
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}

/*
5 5
.....
...!.
.....
.....
.....
*/

/*
5 8
........
...!....
....!...
........
...!....
*/

/*
3 3
!!!
!.!
!!!
*/
