#include <iostream>
#include <vector>
#include <sstream>

using std::string;

// Iterator & Reverse Iterator
class Solution {
public:
    bool isPalindrome(string s) {
        std::stringstream resultStream{};

        for (char& ch : s)
            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
                resultStream << static_cast<char>(tolower(ch));

        std::string resultStr = resultStream.str();

        auto iter = resultStr.begin();
        auto rIter = resultStr.rbegin();

        while (iter != resultStr.end() && rIter != resultStr.rend()) {
            // std::cout << *iter << ' ' << *rIter << '\n';
            if (*iter != *rIter)
                return false;

            ++iter;
            ++rIter;
        }

        return true;
    }
};

// For loop
class Solution {
public:
    bool isPalindrome(string s) {
        std::stringstream resultStream{};

        for (char &ch: s)
            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
                resultStream << static_cast<char>(tolower(ch));

        const std::string resultStr = resultStream.str();
        const int resultSize = resultStr.size();

        for (int i = 0; i < resultSize / 2; ++i) {
            if (resultStr.at(i) != resultStr.at(resultSize - 1 - i))
                return false;
        }
        return true;
    }
};


int main() {
    Solution s;

    // std::cout << s.isPalindrome("A man, a plan, a canal: Panama");
    // std::cout << s.isPalindrome("race a car");
    // std::cout << s.isPalindrome(" ");
    // std::cout << s.isPalindrome("0P");
    // std::cout << s.isPalindrome("a");
    std::cout << s.isPalindrome("9,8");

    return 0;
}
