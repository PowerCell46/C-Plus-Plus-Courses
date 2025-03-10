#include <iostream>
#include <vector>
#include <sstream>

using std::vector;


class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) // Size cannot be < 3
            return false;

        auto previousIter = arr.begin();

        bool hasUphill = false;
        bool reachedPeak = false; // If reachedPeak => hasDownhill

        for (auto iter = arr.begin() + 1; iter < arr.end(); ++iter) {
            if (reachedPeak && *previousIter <= *iter) // If the peak is reached and the previous element is smalled
                return false;
            if (*iter == *previousIter) // In case of equal elements, return false
                return false;

            if (*iter < *previousIter) { // If the previousIter is bigger, we have reached the peak
                reachedPeak = true;
                previousIter = iter;
                continue;
            }

            hasUphill = true; // Marking that there's an uphill
            previousIter = iter; // Increment the previousIter
        }
        return reachedPeak && hasUphill;
    }
};


int main() {
    Solution s;

    // std::vector<int> nums{0,3,2,1};
    // std::vector<int> nums{2,1};
    // std::vector<int> nums{3,5,5};
    // std::vector<int> nums{0,1,2,3,4,5,6,7,8,9};
    std::vector<int> nums{9,8,7,6,5,4,3,2,1,0};

    std::cout << s.validMountainArray(nums);

    return 0;
}
