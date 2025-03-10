#include <iostream>
#include <vector>
#include <sstream>

using std::vector;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenDigitsCounter{};

        for (const int& num : nums)
            evenDigitsCounter += !(std::to_string(num).size() & 1);

        return evenDigitsCounter;
    }
};


int main() {
    Solution s;

    std::vector<int> nums{12,345,2,6,7896};

    std::cout << s.findNumbers(nums);


    return 0;
}
