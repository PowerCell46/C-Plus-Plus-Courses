#include <iostream>
#include <vector>
#include <sstream>

using std::vector;


class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        char direction = 'n';
        for (auto iter = nums.cbegin(); iter != (nums.cend() - 1); ++iter) {
            if (*iter == *(iter + 1))
                continue;
            if (*iter > *(iter + 1)) { // DESC
                if (direction == 'a')
                    return false;
                if (direction == 'n')
                    direction = 'd';
                
            } else { // ASC
                if (direction == 'd')
                    return false;
                if (direction == 'n')
                    direction = 'a';
            }
        }
        return true;
    }
};


int main() {
    Solution s;

    // std::vector<int> numbers{1,2,2,3};
    // std::vector<int> numbers{6,5,4,4};
    std::vector<int> numbers{1,3,2};

    std::cout << s.isMonotonic(numbers);

    return 0;
}
