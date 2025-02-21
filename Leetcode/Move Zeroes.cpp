#include <iostream>
#include <vector>

using std::vector;


class Solution {
    static bool hasZeroesBeforeNums(const vector<int> &numbers) {
        if (numbers.size() < 2)
            return false;

        bool zeroFound = false;
        for (int number: numbers) {
            if (number == 0)
                zeroFound = true;

            if (zeroFound && number != 0)
                return zeroFound;
        }

        return false;
    }

public:
    vector<int> moveZeroes(vector<int> &nums) {
        while (hasZeroesBeforeNums(nums)) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums.at(i) == 0) {
                    for (int j = i; j < nums.size() - 1; ++j) {
                        if (nums.at(j + 1) != 0) {
                            nums.at(j) += nums.at(j + 1);
                            nums.at(j + 1) = nums.at(j) - nums.at(j + 1);
                            nums.at(j) -= nums.at(j + 1);
                        }
                    }
                }
            }
        }

        // for (int &num: nums)
        //     std::cout << num << ' ';

        return nums;
    }
};


int main() {
    Solution s;

    // std::vector<int> nums{0, 1, 0, 3, 12};
    // std::vector<int> nums{0};
    std::vector<int> nums{0, 0, 1};

    s.moveZeroes(nums);
    return 0;
}
