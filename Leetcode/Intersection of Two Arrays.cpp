#include <iostream>
#include <vector>
#include <set>

using std::vector;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::set<int> num1Set{nums1.begin(), nums1.end()};
        std::set<int> num2Set{nums2.begin(), nums2.end()};

        std::vector<int> intersection;
        intersection.reserve(std::min(num1Set.size(), num2Set.size()));

        for (auto iter = num1Set.begin(); iter != num1Set.end(); ++iter)
            if (int currentInt = *iter; num2Set.contains(currentInt))
                intersection.push_back(currentInt);

        return intersection;
    }
};


int main() {

    Solution s;

    // std::vector<int> first{1,2,2,1}, second{2,2};
    std::vector<int> first{4,9,5}, second{9,4,9,8,4};

    auto result = s.intersection(first, second);

    for (int& el : result)
        std::cout << el << ' ';

    return 0;
}
