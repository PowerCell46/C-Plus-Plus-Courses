#include <iostream>
#include <list>
#include <vector>
#include <sstream>

using std::vector;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::pmr::list<int> numsList{nums.begin(), nums.end()};

        for (int i = 0; i < k; ++i) {
            numsList.push_front(numsList.back());
            numsList.pop_back();
        }

        nums = std::vector<int>{numsList.begin(), numsList.end()};
    }
};


int main() {
    Solution s;

    std::vector<int> nums{{1,2,3,4,5,6,7}};

    s.rotate(nums, 3);

    for (int num : nums)
        std::cout << num << ' ';

    return 0;
}
