#include <iostream>
#include <vector>
#include <sstream>

using std::vector;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        auto iter = nums.begin();
        auto revIter = nums.rbegin();

        while (iter < revIter.base() - 1) {
            if ((*iter & 1) && !(*revIter & 1)) {
                *iter ^= *revIter;
                *revIter ^= *iter;
                *iter ^= *revIter;
                ++iter;
                ++revIter;
            
            } else if (!(*revIter & 1))
                ++iter;
              
            else if ((*iter & 1))
                ++revIter;

            else {
                ++iter;
                ++revIter;
            }
        }
      
        return nums;
    }
};


int main() {
    Solution s;

    // std::vector<int> nums{3,1,2,4};
    // std::vector<int> nums{0};
    std::vector<int> nums{0, 1};

    for (int sortArrayByParity : s.sortArrayByParity(nums))
        std::cout << sortArrayByParity << ' ';

    return 0;
}
