#include <iostream>
#include <vector>
#include <sstream>


int main() {
    int rows, columns;
    std::cin >> rows >> columns;

    // Init Matrix
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new int[columns];

    // Fill the Matrix
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            std::cin >> matrix[i][j];

    // Read the requested Rows
    int requestedRows, requestedColumns;
    std::cin >> requestedRows >> requestedColumns;

    // Format the output
    std::stringstream resultStream{};
    for (int i = 0; i < std::min(rows, requestedRows); ++i) {
        for (int j = 0; j < std::min(columns, requestedColumns); ++j)
            resultStream << matrix[i][j] << ' ';
        resultStream << '\n';
    }

    // Print the output
    std::cout << resultStream.str();


    // Clean up
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
    
    return 0;
}
