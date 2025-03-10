#include <iostream>
#include <vector>
#include <sstream>
#include <set>

using std::vector;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::set<int> doubles{};
        std::set<int> halves{};

        for (const int& num : arr) {
            if (doubles.contains(num) || halves.contains(num))
                return true;
            doubles.insert(num * 2);
            if (!(num & 1))
                halves.insert(num / 2);
        }

        return false;
    }
};

int main() {
    Solution s;

    // std::vector<int> nums{10,2,5,3};
    std::vector<int> nums{5,5};

    std::cout << s.checkIfExist(nums);

    return 0;
}
