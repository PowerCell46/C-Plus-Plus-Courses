#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <numeric>

using std::vector;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::vector<int> numbers(nums.size());
        std::iota(numbers.begin(), numbers.end(), 1);
        std::set<int> numbersSet{numbers.begin(), numbers.end()};

        for (const int& num : nums)
            numbersSet.erase(num);

        return std::vector<int>{numbersSet.begin(), numbersSet.end()};
    }
};

int main() {
    Solution s;

    std::vector<int> nums{4,3,2,7,8,2,3,1};

    for (const int& findDisappearedNumber : s.findDisappearedNumbers(nums))
        std::cout << findDisappearedNumber << ' ';

    return 0;
}
