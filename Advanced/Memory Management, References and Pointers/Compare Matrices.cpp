#include <iostream>
#include <sstream>

#define EQUAL std::string("equal")
#define NOT_EQUAL std::string("not ") + EQUAL


int calculateNumberOfElementsInLine(const std::string &);


int main() {
    int firstMatrixRows, firstMatrixColumns{};
    std::cin >> firstMatrixRows;
    std::cin.ignore();

    // Init the first Matrix
    int **firstMatrix = new int *[firstMatrixRows];

    // Read the first Matrix
    for (int i = 0; i < firstMatrixRows; ++i) {
        std::string currentLine;
        std::getline(std::cin, currentLine);

        if (i == 0)
            firstMatrixColumns = calculateNumberOfElementsInLine(currentLine);

        firstMatrix[i] = new int[firstMatrixColumns];

        std::stringstream currentLineStream{currentLine};
        for (int j = 0; j < firstMatrixColumns; ++j)
            currentLineStream >> firstMatrix[i][j];
    }

    /**************************************/

    int secondMatrixRows, secondMatrixColumns{};
    std::cin >> secondMatrixRows;
    std::cin.ignore();

    // Init the second Matrix
    int **secondMatrix = new int *[secondMatrixRows];

    // Read the second Matrix
    for (int i = 0; i < secondMatrixRows; ++i) {
        std::string currentLine;
        std::getline(std::cin, currentLine);

        if (i == 0)
            secondMatrixColumns = calculateNumberOfElementsInLine(currentLine);

        secondMatrix[i] = new int[secondMatrixColumns];

        std::stringstream currentLineStream{currentLine};
        for (int j = 0; j < secondMatrixColumns; ++j)
            currentLineStream >> secondMatrix[i][j];
    }

    if ( // If the two Matrices have the same sizes
        firstMatrixRows == secondMatrixRows &&
        firstMatrixColumns == secondMatrixColumns
    ) {
        for (int i = 0; i < firstMatrixRows; ++i)
            for (int j = 0; j < firstMatrixColumns; ++j)
                if (firstMatrix[i][j] != secondMatrix[i][j]) {
                    // If the current element is different
                    std::cout << NOT_EQUAL;

                    // Clean up rows
                    for (int r = 0; r < firstMatrixRows; ++r)
                        delete[] firstMatrix[r];

                    for (int r = 0; r < firstMatrixRows; ++r)
                        delete[] secondMatrix[r];

                    // Clean up matrices
                    delete[] firstMatrix;
                    delete[] secondMatrix;

                    return 0;
                }

        std::cout << EQUAL;
    } else
        std::cout << NOT_EQUAL;


    // Clean up rows
    for (int r = 0; r < firstMatrixRows; ++r)
        delete[] firstMatrix[r];

    // Clean up matrices
    for (int r = 0; r < firstMatrixRows; ++r)
        delete[] secondMatrix[r];

    delete[] firstMatrix;
    delete[] secondMatrix;

    return 0;
}


int calculateNumberOfElementsInLine(const std::string &line) {
    int numberOfElements = 1;
    for (const char &ch: line)
        if (ch == ' ')
            numberOfElements++;

    return numberOfElements;
}
