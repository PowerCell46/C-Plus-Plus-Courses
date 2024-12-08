
#include <iostream>
#include <sstream>


#define EQUAL std::string("equal")
#define NOT_EQUAL std::string("not ") + EQUAL


int main() {
    int firstMatrixRows, firstMatrixColumns;
    std::cin >> firstMatrixRows;
    std::cin.ignore();

    // init first matrix
    int** firstMatrix = new int*[firstMatrixRows];

    // seed the first matrix
    for (int row = 0; row < firstMatrixRows; ++row) {
        // initialize and read the currentLine
        std::string currentLine;
        std::getline(std::cin, currentLine);
        std::stringstream currentLineStream{currentLine};

        // count the number of columns for this row
        int numberOfColumns = 0, currentElement;
        while (currentLineStream >> currentElement)
            numberOfColumns++;
        // create a row with that size
        firstMatrix[row] = new int[numberOfColumns];
        firstMatrixColumns = numberOfColumns;

        // set the elements in the new row
        std::stringstream lineStream{currentLine};
        int currentIndex = 0;
        while (lineStream >> currentElement) {
            firstMatrix[row][currentIndex] = currentElement;
            currentIndex++;
        }
    }
    
// ---------------------------------------------------------
    
    int secondMatrixRows, secondMatrixColumns;
    std::cin >> secondMatrixRows;
    std::cin.ignore();

    // init second matrix
    int** secondMatrix = new int*[secondMatrixRows];

    // seed the second matrix
    for (int row = 0; row < secondMatrixRows; ++row) {
        // initialize and read the currentLine
        std::string currentLine;
        std::getline(std::cin, currentLine);
        std::stringstream currentLineStream{currentLine};

        // count the number of columns for this row
        int numberOfColumns = 0, currentElement;
        while (currentLineStream >> currentElement)
            numberOfColumns++;
        secondMatrix[row] = new int[numberOfColumns];
        secondMatrixColumns = numberOfColumns;

        // set the elements in the new row
        std::stringstream lineStream{currentLine};
        int currentIndex = 0;
        while (lineStream >> currentElement) {
            secondMatrix[row][currentIndex] = currentElement;
            currentIndex++;
        }
    }

// ---------------------------------------------------------

    // different matrix sizes
    if (firstMatrixRows != secondMatrixRows || firstMatrixColumns != secondMatrixColumns) {
        std::cout << NOT_EQUAL << std::endl;

        for (int i = 0; i < firstMatrixRows; ++i)
            delete[] firstMatrix[i];
        delete[] firstMatrix;

        for (int i = 0; i < secondMatrixRows; ++i)
            delete[] secondMatrix[i];
        delete[] secondMatrix;

        return 0;
    }

// ---------------------------------------------------------

    // compare the elements
    for (int row = 0; row < firstMatrixRows; ++row) {
        for (int col = 0; col < firstMatrixColumns; ++col) {
            if (firstMatrix[row][col] != secondMatrix[row][col]) {
                std::cout << NOT_EQUAL << std::endl;

                for (int i = 0; i < firstMatrixRows; ++i)
                    delete[] firstMatrix[i];
                delete[] firstMatrix;

                for (int i = 0; i < secondMatrixRows; ++i)
                    delete[] secondMatrix[i];
                delete[] secondMatrix;

                return 0;
            }
        }
    }

    // no differences were found
    std::cout << EQUAL << std::endl;

// ---------------------------------------------------------

    // cleanup the matrices
    for (int i = 0; i < firstMatrixRows; ++i)
        delete[] firstMatrix[i];
    delete[] firstMatrix;

    for (int i = 0; i < secondMatrixRows; ++i)
        delete[] secondMatrix[i];
    delete[] secondMatrix;


    return 0;
}
