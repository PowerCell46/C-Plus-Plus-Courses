#include <iostream>
#include <set>
#include <vector>
#include <sstream>

using std::vector;
typedef std::vector<int> intVector;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCounter = 0;
        int counter = 0;

        for (auto iter = nums.begin(); iter != nums.end(); ++iter)
            switch (*iter) {
                case 0: {
                    if (counter > maxCounter)
                        maxCounter = counter;
                    counter = 0;
                    break;
                }
                default:
                    counter++;
            }
        if (counter > maxCounter)
            return counter;

        return maxCounter;
    }
};

int main() {
    Solution s;
    // intVector nums{1,1,0,1,1,1};
    intVector nums{1,0,1,1,0,1};

    std::cout << s.findMaxConsecutiveOnes(nums);

    return 0;
}
