#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>


using std::vector;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int> &arr) {
        std::sort(arr.begin(), arr.end());

        int diff = std::abs(*(arr.begin()) - *(arr.begin() + 1));

        for (auto iter = arr.begin() + 1; iter != arr.end(); ++iter)
            if (std::abs(*iter - *(iter - 1)) != diff)
                return false;

        return true;
    }
};


int main() {

    Solution s;

    // std::vector<int> nums{3,5,1};
    // std::vector<int> nums{1, 2, 4};
    std::vector<int> nums{3, 5, 1};

    std::cout << s.canMakeArithmeticProgression(nums);

    return 0;
}
