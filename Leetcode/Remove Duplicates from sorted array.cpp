#include <iostream>
#include <vector>
#include <sstream>
#include <set>

using std::vector;


class Solution {
    void shrinkArray(std::vector<int>& numbersVector, const int& index) {
        for (int i = index; i < numbersVector.size() - 1; ++i)
            numbersVector.at(i) = numbersVector.at(i + 1);
        numbersVector.pop_back();
    }
public:
    int removeDuplicates(vector<int>& nums) {
        std::set<int> numsSet{};

        for (int i = 0; i < nums.size(); ++i) {
            if (numsSet.contains(nums.at(i))) {
                shrinkArray(nums, i);
                --i;
            } else
                numsSet.insert(nums.at(i));
        }

        return numsSet.size();
    }
};


int main() {
    Solution s;

    // std::vector<int> nums{1,1,2,1};
    std::vector<int> nums{0,0,1,1,1,2,2,3,3,4};

    s.removeDuplicates(nums);

    for (int num : nums)
        std::cout << num << ' ';

    return 0;
}
