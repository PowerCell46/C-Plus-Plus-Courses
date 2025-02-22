#include <iostream>
#include <vector>
#include <sstream>

using std::vector;


class Solution {
public:
    int averageValue(vector<int>& nums) {
        int count{}, sum{};
        for (const int& num : nums) {
            if ((!(num & 1)) && num % 3 == 0) {
                count++;
                sum += num;
            }
        }
        return count != 0 ? sum / count : 0;
    }
};

int main() {
    Solution s;

    // std::vector<int> vals{1,3,6,10,12,15};
    std::vector<int> vals{1,2,4,7,10};

    std::cout << s.averageValue(vals);

    return 0;
}
