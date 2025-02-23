#include <iostream>
#include <vector>
#include <sstream>

using std::vector;


class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int cutDownIndices = 0;

        while (true) {
            auto middleIter = nums.begin() + (nums.size() / 2);

            if (*middleIter == target)
                return middleIter - nums.begin() + cutDownIndices;
            
            if (*middleIter > target)
                nums = std::vector<int>{nums.begin(), middleIter};

            else if (*middleIter < target) {
                cutDownIndices += middleIter + 1 - nums.begin();
                nums = std::vector<int>{middleIter + 1, nums.end()};
            }
            
            if (nums.empty())
                return cutDownIndices;
        }
    }
};


int main() {
    Solution s;

    std::vector<int> nums{1,3,5,6};

    std::cout << s.searchInsert(nums, 7);

    return 0;
}
