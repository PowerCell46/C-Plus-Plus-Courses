#include <iostream>
#include <sstream>

#define MATRIX_SIZE 10
#define HEALTHY_CELL '.'
#define RUST_RESISTANT_CELL '#'
#define BEGIN_TO_RUST_CELL '!'
#define TEMP_RUST_CELL '-'


int main() {
    char** matrix = new char*[10];
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        matrix[i] = new char[i];

        for (int j = 0; j < MATRIX_SIZE; ++j)
            std::cin >> matrix[i][j];
    }

    int cycles;
    std::cin >> cycles;


    for (int cycle = 0; cycle < cycles; ++cycle) {

        for (int i = 0; i < MATRIX_SIZE; ++i) {
            for (int j = 0; j < MATRIX_SIZE; ++j) {
                if (matrix[i][j] == BEGIN_TO_RUST_CELL) {
                    if (i > 0 && matrix[i - 1][j] == HEALTHY_CELL)
                        matrix[i - 1][j] = TEMP_RUST_CELL;
                    if (i < 9 && matrix[i + 1][j] == HEALTHY_CELL)
                        matrix[i + 1][j] = TEMP_RUST_CELL;
                    if (j > 0 && matrix[i][j - 1] == HEALTHY_CELL)
                        matrix[i][j - 1] = TEMP_RUST_CELL;
                    if (j < 9 && matrix[i][j + 1] == HEALTHY_CELL)
                        matrix[i][j + 1] = TEMP_RUST_CELL;
                }
            }
        }

        for (int i = 0; i < MATRIX_SIZE; ++i)
            for (int j = 0; j < MATRIX_SIZE; ++j)
                if (matrix[i][j] == TEMP_RUST_CELL)
                    matrix[i][j] = BEGIN_TO_RUST_CELL;
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j)
            std::cout << matrix[i][j];
        std::cout << '\n';
        delete matrix[i];
    }

    delete[] matrix;

    return 0;
}

