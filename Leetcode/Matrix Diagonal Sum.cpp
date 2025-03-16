#include <iostream>
#include <vector>
#include <sstream>
#include <set>

using std::string;
using std::vector;


class Solution {
public:
    int diagonalSum(vector<vector<int> > &mat) {
        std::set<std::string> alreadyAddedPositions{};
        int diagonalSum{};

        for (auto rowIter = mat.cbegin(); rowIter != mat.cend(); ++rowIter) {
            for (auto colIter = rowIter->cbegin(); colIter != rowIter->cend(); ++colIter)
                if (
                    rowIter - mat.cbegin() == colIter - rowIter->cbegin() || // 0, 0
                    (mat.cend() - mat.cbegin()) - 1 - (rowIter - mat.cbegin()) == colIter - rowIter->cbegin() || // 2, 0
                    rowIter - mat.cbegin() == (rowIter->cend() - rowIter->cbegin()) - 1 - (colIter - rowIter->cbegin()) // 0, 2
                )
                    if (
                        std::string currentPosition = std::to_string(rowIter - mat.cbegin()) + "," + std::to_string(colIter - rowIter->cbegin());
                        !alreadyAddedPositions.contains(currentPosition)
                    ) {
                        alreadyAddedPositions.insert(currentPosition);
                        diagonalSum += *colIter;
                    }
        }

        return diagonalSum;
    }
};


int main() {
    Solution s;

    // std::vector<std::vector<int> > matrix{
    //     {1, 1, 1, 1},
    //     {1, 1, 1, 1},
    //     {1, 1, 1, 1},
    //     {1, 1, 1, 1}
    // };

    // std::vector<std::vector<int>> matrix{
    //     {1,2,3},
    //     {4,5,6},
    //     {7,8,9}
    // };

    std::vector<std::vector<int>> matrix {
        {5,10,5,4,8,18,14,19,7,14,7,11},
        {17,18,13,3,16,16,11,6,6,2,15,9},
        {11,16,14,11,11,12,17,16,4,7,8,1},
        {8,18,4,7,16,11,12,16,9,18,10,15},
        {1,13,12,11,1,9,19,8,16,9,16,9},
        {20,12,10,1,19,16,17,7,7,16,6,2},
        {11,20,2,3,17,14,14,11,14,2,16,14},
        {3,1,19,2,15,4,11,17,1,4,5,2},
        {9,9,4,12,10,16,15,3,17,12,17,11},
        {10,4,4,1,5,16,16,18,2,7,16,1},
        {8,15,2,10,16,10,7,16,20,20,12,13},
        {11,10,11,16,15,1,12,10,17,8,13,16}
    };

    std::cout << s.diagonalSum(matrix);

    return 0;
}
