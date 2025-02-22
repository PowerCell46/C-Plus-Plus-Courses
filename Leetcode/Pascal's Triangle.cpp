#include <iostream>
#include <vector>
#include <sstream>

using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> matrix;
        matrix.reserve(numRows);

        for (int i = 0; i < numRows; ++i) {
            if (i == 0)
                matrix.push_back({1});
            else if (i == 1)
                matrix.push_back({1, 1});
            else {
                std::vector<int> currentRow;
                for (int j = 0; j <= i; ++j) {
                    if (j == 0 || j == i)
                        currentRow.push_back(1);
                    else
                        currentRow.push_back(matrix.at(i - 1).at(j - 1) + matrix.at(i - 1).at(j));
                }
                matrix.push_back(currentRow);
            }
            // for (int matrix1 : matrix.at(i))
            //     std::cout << matrix1 << ' ';
            // std::cout << '\n';
        }

        return matrix;
    }
};


int main() {

    Solution s;

    s.generate(1);
    return 0;
}
