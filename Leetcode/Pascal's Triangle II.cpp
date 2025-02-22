#include <iostream>
#include <vector>
#include <sstream>

using std::vector;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<std::vector<int> > matrix;
        matrix.reserve(rowIndex);

        for (int i = 0; i <= rowIndex; ++i) {
            std::vector<int> currentRow;

            if (i == 0)
                currentRow.push_back(1);
            else if (i == 1) {
                currentRow.push_back(1);
                currentRow.push_back(1);
            } else {
                for (int j = 0; j <= i; ++j) {
                    if (j == 0 || j == i)
                        currentRow.push_back(1);
                    else
                        currentRow.push_back(matrix.at(i - 1).at(j - 1) + matrix.at(i - 1).at(j));
                }
            }
            matrix.push_back(currentRow);
            if (i == rowIndex)
                return currentRow;
        }

        return matrix.at(0);
    }
};


int main() {
    Solution s;

    for (const int& row : s.getRow(3))
        std::cout << row << ' ';

    return 0;
}
