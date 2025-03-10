#include <iostream>
#include <vector>
#include <sstream>

using std::vector;


class Solution {
    void shrinkArray(std::vector<int>& numbersVector, const int& index) {
        for (int i = index; i < numbersVector.size() - 1; ++i)
            numbersVector.at(i) = numbersVector.at(i + 1);
        numbersVector.pop_back();
    }
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums.at(i) == val) {
                shrinkArray(nums, i);
                --i;
            }
        }

        return nums.size();
    }
};


int main() {
    Solution s;

    // std::vector<int> nums{3,2,2,3};
    //
    // std::cout << '\n' << s.removeElement(nums, 3);

    std::vector<int> nums{0,1,2,2,3,0,4,2};

    std::cout << '\n' << s.removeElement(nums, 2);

    return 0;
}
