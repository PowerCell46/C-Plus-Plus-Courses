#include <iostream>
#include <vector>
#include <sstream>

using std::vector;


class Solution {
    static int calculateSumOfPrevious(const int& num) {
        if (num == 1)
            return num;
        return num + calculateSumOfPrevious(num - 1);
    }
public:
    int missingNumber(vector<int>& nums) {
        int factorial = calculateSumOfPrevious(nums.size());
        for (int& num : nums)
            factorial -= num;

        return factorial;
    }
};


int main() {
    Solution s;

    vector<int> nums {3, 0, 1};
    // vector<int> nums {0, 1};
    // vector<int> nums {9,6,4,2,3,5,7,0,1};

    std::cout << s.missingNumber(nums);

    return 0;
}
