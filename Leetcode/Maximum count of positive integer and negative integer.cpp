#include <iostream>
#include <vector>
#include <sstream>

using std::vector;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // Check if the first one and the last one are positive or negative
        if (*nums.begin() > 0 && *(nums.end() -1) > 0 || *nums.begin() < 0 && *(nums.end() -1) < 0)
            return nums.end() - nums.begin();
        // Check if the first one and the last one are zeroes
        if (*nums.begin() == 0 && *(nums.end() - 1) == 0)
            return 0;

        auto middleIter = nums.begin() + nums.size() / 2;
        int positiveStartIndex = -1, negativeStartIndex = -1;
        bool foundZeroes = false;

        while ((positiveStartIndex == -1 || negativeStartIndex == -1) && middleIter != nums.begin() && middleIter != nums.end()) {
            if (*middleIter > 0) { // If the current number is positive: set the positive index
                positiveStartIndex = middleIter - nums.begin();
                if (foundZeroes)
                    break;
                --middleIter;

            } else if (*middleIter < 0) { // If the current number is negative: set the negative index
                negativeStartIndex = middleIter - nums.begin();
                ++middleIter;

            } else { // if (*middleIter == 0) // increment the middle iter until the end
                ++middleIter;
                foundZeroes = true;
            }
        }

        if (foundZeroes && negativeStartIndex == -1) { // If zeroes were found: Decrement the middle iter until the beginning
            middleIter = nums.begin() + nums.size() / 2; // Reset the middleIter

            while (middleIter != nums.begin()) {
                if (*middleIter < 0) {
                    negativeStartIndex = middleIter - nums.begin();
                    break;
                }
                --middleIter;
            }
        }
        if (positiveStartIndex == -1) // If none positive numbers were found
            positiveStartIndex = nums.size();

        // Calculate the number of positive and negative elements and return the bigger value
        return (nums.size() - positiveStartIndex) >= (negativeStartIndex + 1) ? (nums.size() - positiveStartIndex) : (negativeStartIndex + 1);
    }
};

int main() {
    Solution s;

    // std::vector<int> nums{-5, 20, 66, 1314};
    // std::vector<int> nums{-2,-1,-1,1,2,3};
    // std::vector<int> nums{-3,-2,-1,0,0,1,2};
    // std::vector<int> nums{-2,-1,-1,1,2,3};
    // std::vector<int> nums{-1563,-236,-114,-55,427,447,687,752,1021,1636};
    // std::vector<int> nums{-2,-1,-1,0,0,0};
    // std::vector<int> nums{-2,-1,-1,0,0,0};
    std::vector<int> nums{0,0,66,1314};

    std::cout << s.maximumCount(nums);

    return 0;
}
