#include <iostream>
#include <vector>
#include <sstream>

using std::vector;

class Solution {
    void shiftArrayWithZero(std::vector<int>& numbersVector, std::vector<int>::iterator iter) {
        for (auto currentIter = numbersVector.end() - 1; currentIter != iter; --currentIter)
            *currentIter = *(currentIter - 1);
    }
public:
    void duplicateZeros(vector<int>& arr) {
        for (auto iter = arr.begin(); iter < arr.end(); ++iter) {
            if (*iter == 0) {
                shiftArrayWithZero(arr, iter);
                ++iter;
            }
        }
    }
};

int main() {
    Solution s;

    std:;vector<int> nums{1,0,2,3,0,4,5,0};
    // std:;vector<int> nums{1,2,3};
    // std:;vector<int> nums{0,0,0,0,0,0,0};

    s.duplicateZeros(nums);

    for (int& num : nums)
        std::cout << num << ' ';

    return 0;
}
