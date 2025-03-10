#include <iostream>
#include <vector>
#include <sstream>

using std::vector;


class Solution {
    int findMaxElement(std::vector<int>& numbersVector, const std::vector<int>::iterator iter) {
        int maxElement = *(iter + 1);
        for (auto currentIter = (iter + 2); currentIter != numbersVector.end(); ++currentIter)
            maxElement = std::max(maxElement, *currentIter);

        return maxElement;
    }
public:
    vector<int> replaceElements(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; ++i)
            arr.at(i) = findMaxElement(arr, arr.begin() + i);
        *(arr.end() - 1) = -1;

        return arr;
    }
};


int main() {
    Solution s;

    // std::vector<int> nums{17,18,5,4,6,1};
    std::vector<int> nums{400};

    s.replaceElements(nums);

    for (int num : nums)
        std::cout << num << ' ';

    return 0;
}
