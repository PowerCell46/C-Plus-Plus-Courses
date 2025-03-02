#include <iostream>
#include <vector>
#include <sstream>

using std::vector;


class Solution {
public:
    int arraySign(vector<int> &nums) {
        int product = 1;

        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            if (*iter == 0)
                return 0;
            product *= (*iter > 0 ? 1 : -1);
        }

        return product > 0 ? 1 : -1;
    }
};


int main() {

    Solution s;

    // std::vector<int> nums{-1, -2, -3, -4, 3, 2, 1};
    // std::vector<int> nums{1, 5, 0, 2, -3};
    std::vector<int> nums{-1, 1, -1, 1, -1};


    std::cout << s.arraySign(nums);

    return 0;
}
