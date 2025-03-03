#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using std::string;


class Solution {
public:
    string addStrings(string num1, string num2) {
        auto num1RevIter = num1.rbegin();
        auto num2RevIter = num2.rbegin();

        std::stringstream resultNumberStream{};

        int previousLeftOut{};

        while (true) {
            int currentSum =
                    (num1RevIter != num1.rend() ? *num1RevIter - 48 : 0) +
                    (num2RevIter != num2.rend() ? *num2RevIter - 48 : 0) +
                    previousLeftOut;
            previousLeftOut = 0;

            if (currentSum == 0 && num1RevIter == num1.rend() && num2RevIter == num2.rend())
                break;
            if (currentSum >= 10) {
                ++previousLeftOut;
                currentSum -= 10;
            }
            resultNumberStream << currentSum;
            if (num1RevIter != num1.rend())
                ++num1RevIter;
            if (num2RevIter != num2.rend())
                ++num2RevIter;
        }

        std::string resultStr = resultNumberStream.str();
        if (resultStr.empty())
            return "0";

        std::reverse(resultStr.begin(), resultStr.end());
        return resultStr;
    }
};


int main() {
    Solution s;

    // std::cout << s.addStrings("11", "123");
    // std::cout << s.addStrings("456", "77");
    // std::cout << s.addStrings("0", "0");
    // std::cout << s.addStrings("9", "9");
    std::cout << s.addStrings("501", "6");

    return 0;
}
