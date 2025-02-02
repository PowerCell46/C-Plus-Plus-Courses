#include <iostream>
#include <sstream>

#define HEALTHY_TYPE '.'
#define RUST_RESISTANT_TYPE '#'
#define BEGIN_TO_RUST_TYPE '!'
#define TEMP_RUST_TYPE '&'


void spreadRustCycle(char **, const int &);


int main() {
    constexpr int MATRIX_SIZE = 10;

    // Init the Matrix
    char **matrix = new char *[MATRIX_SIZE];

    // Init the rows and read the matrix
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        matrix[i] = new char[MATRIX_SIZE];
        for (int j = 0; j < MATRIX_SIZE; ++j)
            std::cin >> matrix[i][j];
    }

    int numberOfCycles;
    std::cin >> numberOfCycles;

    // Call the spread rust the number of cycles
    for (int i = 0; i < numberOfCycles; ++i)
        spreadRustCycle(matrix, MATRIX_SIZE);

    // Print the result + delete the rows
    std::stringstream resultStream{};
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j)
            resultStream << matrix[i][j];
        resultStream << '\n';
        delete[] matrix[i];
    }
    std::cout << resultStream.str();

    // Delete the matrix
    delete[] matrix;

    return 0;
}


void spreadRustCycle(char **matrix, const int &MATRIX_SIZE) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            if (matrix[i][j] == BEGIN_TO_RUST_TYPE) { // If the current element has begun to rust
                if (i > 0 && matrix[i - 1][j] == HEALTHY_TYPE) // Up
                    matrix[i - 1][j] = TEMP_RUST_TYPE;

                if (j < MATRIX_SIZE - 1 && matrix[i][j + 1] == HEALTHY_TYPE) // Right
                    matrix[i][j + 1] = TEMP_RUST_TYPE;

                if (i < MATRIX_SIZE - 1 && matrix[i + 1][j] == HEALTHY_TYPE) // Down
                    matrix[i + 1][j] = TEMP_RUST_TYPE;

                if (j > 0 && matrix[i][j - 1] == HEALTHY_TYPE) // Left
                    matrix[i][j - 1] = TEMP_RUST_TYPE;
            }
        }
    }

    for (int i = 0; i < MATRIX_SIZE; ++i) // Replace the Temp Rust with the actual Rust Symbol
        for (int j = 0; j < MATRIX_SIZE; ++j)
            if (matrix[i][j] == TEMP_RUST_TYPE)
                matrix[i][j] = BEGIN_TO_RUST_TYPE;
}

/*
..........
....!.....
..........
..........
..........
..........
..........
..........
..........
..........
4
*/

/*
..........
....!.....
...###....
..........
..........
..........
..........
..........
..........
..........
5
*/

/*
!........!
..........
..........
..........
..........
..........
..........
..........
..........
!........!
5
*/
