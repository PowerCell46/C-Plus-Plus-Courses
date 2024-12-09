#include <iostream>
#include <sstream>


int main() {
    int matrixRows, matrixColumns;
    std::cin >> matrixRows >> matrixColumns;


    char **matrix = new char *[matrixRows];
    for (int i = 0; i < matrixRows; ++i)
        matrix[i] = new char[matrixColumns];


    std::string word;
    std::cin >> word;
    int currentWordIndex = 0;
    std::stringstream resultStream{};


    for (int row = 0; row < matrixRows; ++row) {
        if (!(row & 1)) { // even rows

            for (int col = 0; col < matrixColumns; ++col) {
                matrix[row][col] = word[currentWordIndex++];

                if (currentWordIndex == word.length())
                    currentWordIndex = 0;

                resultStream << matrix[row][col];
            }

        } else { // odd rows

            for (int col = matrixColumns - 1; col > -1; --col) {
                matrix[row][col] = word[currentWordIndex++];

                if (currentWordIndex == word.length())
                    currentWordIndex = 0;
            }

            for (int col = 0; col < matrixColumns; ++col)
                resultStream << matrix[row][col];

        }

        resultStream << '\n';
    }


    std::cout << resultStream.str() << std::endl;


    // cleanup
    for (int i = 0; i < matrixRows; ++i)
        delete[] matrix[i];
    delete[] matrix;


    return 0;
}
