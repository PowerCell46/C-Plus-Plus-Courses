#include <iostream>
#include <vector>
#include <sstream>

using std::vector;


#define TEMP_VALUE (INT_MAX - 10)
class Solution {
    void setZeroRowAndCol(std::vector<std::vector<int>>& matrix, const int& rowIndex, const int& colIndex) {
        for (int i = 0; i < matrix.size(); ++i)
            matrix[i][colIndex] = matrix[i][colIndex] != 0 ? TEMP_VALUE : 0;

        for (int i = 0; i < matrix[0].size(); ++i)
            matrix[rowIndex][i] = matrix[rowIndex][i] != 0 ? TEMP_VALUE : 0;
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        for (auto rowIter = matrix.begin(); rowIter != matrix.end(); ++rowIter) {
            for (auto colIter = rowIter->begin(); colIter != rowIter->end(); ++colIter) {
                if (*colIter == 0) {
                    setZeroRowAndCol(matrix, rowIter - matrix.begin(), colIter - rowIter->begin());
                }
            }
        }

        for (auto rowIter = matrix.begin(); rowIter != matrix.end(); ++rowIter) {
            for (auto colIter = rowIter->begin(); colIter != rowIter->end(); ++colIter) {
                if (*colIter == TEMP_VALUE)
                    *colIter = 0;
            }
        }
    }
};


int main() {
    Solution s;

    // std::vector<std::vector<int>> matrix = {{1, 1, 1},{1, 0, 1},{1, 1, 1}};
    // std::vector<std::vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    std::vector<std::vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    s.setZeroes(matrix);

    for (std::vector<int>& vector : matrix) {
        for (const int& vector1 : vector)
            std::cout << vector1 << ' ';
        std::cout << '\n';
    }

    return 0;
}
