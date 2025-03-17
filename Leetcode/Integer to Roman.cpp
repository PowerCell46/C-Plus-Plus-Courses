#include <iostream>
#include <vector>
#include <sstream>

using std::string;

#define ONE_THOUSAND std::pair<char, int> {'M', 1'000}
#define NINE_HUNDRED std::pair<std::string, int> {"CM", 900}
#define FIVE_HUNDRED std::pair<char, int> {'D', 500}
#define FOUR_HUNDRED std::pair<std::string, int> {"CD", 400}
#define HUNDRED std::pair<char, int> {'C', 100}
#define NINETY std::pair<std::string, int> {"XC", 90}
#define FIFTY std::pair<char, int> {'L', 50}
#define FORTY std::pair<std::string, int> {"XL", 40}
#define TEN std::pair<char, int> {'X', 10}
#define NINE std::pair<std::string, int> {"IX", 9}
#define FIVE std::pair<char, int> {'V', 5}
#define FOUR std::pair<std::string, int> {"IV", 4}
#define ONE std::pair<char, int> {'I', 1}


class Solution {
public:
    string intToRoman(int num) {
        std::stringstream resultRomanStream{};

        resultRomanStream << std::string(num / ONE_THOUSAND.second, ONE_THOUSAND.first);
        num %= ONE_THOUSAND.second;

        if (num / NINE_HUNDRED.second) {
            resultRomanStream << NINE_HUNDRED.first;
            num %= NINE_HUNDRED.second;
        }

        resultRomanStream << std::string(num / FIVE_HUNDRED.second, FIVE_HUNDRED.first);
        num %= FIVE_HUNDRED.second;

        if (num / FOUR_HUNDRED.second) {
            resultRomanStream << FOUR_HUNDRED.first;
            num %= FOUR_HUNDRED.second;
        }

        resultRomanStream << std::string(num / HUNDRED.second, HUNDRED.first);
        num %= HUNDRED.second;

        if (num / NINETY.second) {
            resultRomanStream << NINETY.first;
            num %= NINETY.second;
        }

        resultRomanStream << std::string(num / FIFTY.second, FIFTY.first);
        num %= FIFTY.second;

        if (num / FORTY.second) {
            resultRomanStream << FORTY.first;
            num %= FORTY.second;
        }

        resultRomanStream << std::string(num / TEN.second, TEN.first);
        num %= TEN.second;

        if (num / NINE.second) {
            resultRomanStream << NINE.first;
            num %= NINE.second;
        }

        resultRomanStream << std::string(num / FIVE.second, FIVE.first);
        num %= FIVE.second;

        if (num / FOUR.second) {
            resultRomanStream << FOUR.first;
            num %= FOUR.second;
        }

        resultRomanStream << std::string(num, ONE.first);
        num = 0;

        return resultRomanStream.str();
    }
};


int main() {
    Solution s;

    // std::cout << s.intToRoman(3749);
    std::cout << s.intToRoman(58);

    return 0;
}
