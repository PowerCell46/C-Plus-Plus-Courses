#include <iostream>
#include <vector>
#include <sstream>

using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        std::stringstream numStream{};

        bool hasToIncrement = true;

        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter)
            if (hasToIncrement) {
                if (*iter + 1 == 10)
                    if (iter + 1 == digits.rend())
                        numStream << 1;
                    else
                        numStream << 0;
                else {
                    numStream << *iter + 1;
                    hasToIncrement = false;
                }
            } else
                numStream << *iter;

        std::string resultNumberStr = numStream.str();
        std::vector<int> resultVector;
        resultVector.reserve(resultNumberStr.size());

        for (auto iter = resultNumberStr.rbegin(); iter != resultNumberStr.rend(); ++iter)
            resultVector.push_back(*iter - 48);

        if (hasToIncrement)
            resultVector.push_back(0);

        return resultVector;
    }
};

int main() {
    // std::vector<int> nums{8,9,9,9};
    // std::vector<int> nums{4,3,2,1};
    // std::vector<int> nums{1,2,3};

    Solution s;
    for (int plus_one : s.plusOne(nums))
        std::cout << plus_one;

    return 0;
}
