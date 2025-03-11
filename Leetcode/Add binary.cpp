#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using std::string;


class Solution {
public:
    string addBinary(string a, string b) {
        auto firstStrRevIter = a.rbegin();
        auto secondStrRevIter = b.rbegin();

        std::stringstream resultStream{};
        bool previousIncrement = false;

        while (firstStrRevIter != a.rend() || secondStrRevIter != b.rend()) {
            int currentSum = previousIncrement;
            previousIncrement = false;

            if (firstStrRevIter != a.rend()) {
                currentSum += *firstStrRevIter - '0';
                ++firstStrRevIter;
            }

            if (secondStrRevIter != b.rend()) {
                currentSum += *secondStrRevIter - '0';
                ++secondStrRevIter;
            }

            if (currentSum > 1) {
                currentSum -= 2;
                previousIncrement = true;
            }

            resultStream << currentSum;
        }

        if (previousIncrement)
            resultStream << 1;

        std::string result = resultStream.str();
        std::reverse(result.begin(), result.end());
        return result;
    }
};


int main() {
    Solution s;

    // std::cout << s.addBinary("11", "1");
    std::cout << s.addBinary("1010", "1011");

    return 0;
}
