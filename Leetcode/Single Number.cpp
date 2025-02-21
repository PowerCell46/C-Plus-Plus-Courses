#include <iostream>
#include <vector>
#include <sstream>

using std::vector;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = nums.at(0);

        for (int i = 1; i < nums.size(); ++i)
            num ^= nums.at(i);

        return num;
    }
};


int main() {
    Solution s;

    std::vector<int> nums{2, 2, 1};
    // std::vector<int> nums{4,1,2,1,2};
    // std::vector<int> nums{1};

    std::cout << s.singleNumber(nums);

    return 0;
}

/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::unordered_map<int, bool> numberOccurrences;

        for (int& num : nums) {
            if (numberOccurrences[num])
                numberOccurrences.erase(num);
            else
                numberOccurrences[num] = true;
        }

        for (auto number_occurrence : numberOccurrences)
            return number_occurrence.first;

        return 0;
    }
};
*/
