#include <iostream>
#include <vector>
#include <sstream>

using std::string;


class Solution {
public:
    int myAtoi(string s) {
        std::stringstream numberStream{};
        bool operatorWasUsed = false;

        auto iter = s.begin();

        while (*iter == ' ' && iter != s.end())
            ++iter;
        if (*iter == '+') {
            operatorWasUsed = true;
            ++iter;
        }
        if (*iter == '-') {
            if (operatorWasUsed)
                return 0;
            numberStream << *iter;
            ++iter;
        }

        while (*iter == '0' && iter != s.end())
            ++iter;

        while (iter != s.end()) {
            if (*iter < '0' || *iter > '9')
                break;
            numberStream << *iter;
            ++iter;
        }
        
        try {
            int number = std::stoi(numberStream.str());
            number = std::min(number, INT_MAX);
            number = std::max(number, INT_MIN);
            return number;

        } catch (std::invalid_argument) {
            return 0;
        } catch (std::out_of_range) {
            return numberStream.str().at(0) == '-' ? INT_MIN : INT_MAX;
        }
    }
};


int main() {
    Solution s;

    // std::cout << s.myAtoi("-91283472332");
    std::cout << s.myAtoi("+-12");

    return 0;
}
