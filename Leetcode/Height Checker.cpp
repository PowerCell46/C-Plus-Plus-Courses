#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        std::vector<int> orderedHeights{heights.begin(), heights.end()};
        std::sort(orderedHeights.begin(), orderedHeights.end());

        int countDiffElements{};
        for (int i = 0; i < heights.size(); ++i)
            if (heights[i] != orderedHeights[i])
                ++countDiffElements;

        return countDiffElements;
    }
};

int main() {
    Solution s;

    std::vector<int> nums{1,1,4,2,1,3};


    std::cout << s.heightChecker(nums);

    return 0;
}
