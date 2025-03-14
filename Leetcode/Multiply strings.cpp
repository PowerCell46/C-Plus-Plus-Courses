#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using std::string;


class Solution {
public:
    string multiply(string num1, string num2) {
        std::vector<std::string> multiplicationLines;
        // Vector with the multiplications of the lines
        // 1368
        // 9120
        // 45600
        int maxLength = {};

        // Iterating through the numbers from the first number in reverse
        for (auto nums1Riter = num1.rbegin(); nums1Riter != num1.rend(); ++nums1Riter) {
            std::stringstream resultMultiplication{};

            int previousIncrement = 0;
            // Iterating through the numbers from the second number in reverse
            for (auto nums2Riter = num2.rbegin(); nums2Riter != num2.rend(); ++nums2Riter) {
                int currentMultiplication = ((*nums1Riter) - 48) * ((*nums2Riter) - 48) + previousIncrement;

                if (currentMultiplication > 9) {
                    previousIncrement = currentMultiplication / 10;
                    currentMultiplication %= 10;
                } else
                    previousIncrement = 0;

                resultMultiplication << currentMultiplication;
            }

            if (previousIncrement != 0)
                resultMultiplication << previousIncrement;

            std::string currentResult = resultMultiplication.str();
            std::reverse(currentResult.begin(), currentResult.end());
            currentResult = currentResult + std::string(nums1Riter - num1.rbegin(), '0');

            multiplicationLines.push_back(currentResult);
            maxLength = std::max(maxLength, static_cast<int>(currentResult.size()));
        }

        // Add leading zeroes to the lines with fewer length
        for (std::string& line : multiplicationLines)
            line = std::string(maxLength - line.size(), '0') + line;

        std::stringstream finalMultiplicationStream{};

        int previousIncrement = 0;
        // Sum the lines in reverse order
        for (int i = maxLength - 1; i >= 0; --i) {
            int currentSum = previousIncrement;

            for (std::string& line : multiplicationLines)
                currentSum += line[i] - 48;

            if (currentSum > 9) {
                previousIncrement = currentSum / 10;
                currentSum %= 10;
            } else
                previousIncrement = 0;

            finalMultiplicationStream << currentSum;
        }
        if (previousIncrement != 0)
            finalMultiplicationStream << previousIncrement;

        // Reverse the result, in order to be valid
        std::string finalResultMultiplicationString = finalMultiplicationStream.str();
        std::reverse(finalResultMultiplicationString.begin(), finalResultMultiplicationString.end());

        // If the first char is 0, return directly 0
        return finalResultMultiplicationString[0] != '0' ? finalResultMultiplicationString : "0";
    }
};


int main() {
    Solution s;

    // std::cout << s.multiply("9133", "0");
    // std::cout << s.multiply("120", "100");
    std::cout << s.multiply("123", "456");

    return 0;
}
