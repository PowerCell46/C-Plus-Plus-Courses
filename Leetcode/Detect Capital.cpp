#include <iostream>
#include <sstream>

using std::string;


class Solution {
public:
    bool detectCapitalUse(string word) {
        bool isUppercase = word.at(0) >= 'A' && word.at(0) <= 'Z';

        if (word.size() > 1) {
            if (!isUppercase && (word.at(1) >= 'A' && word.at(1) <= 'Z')) // If the first is lower and the second isn't
                return false;
            isUppercase = word.at(1) >= 'A' && word.at(1) <= 'Z';
        }

        for (int i = 2; i < word.size(); ++i) {
            if (isUppercase && !(word.at(i) >= 'A' && word.at(i) <= 'Z'))
                return false;
            
            if (!isUppercase && (word.at(i) >= 'A' && word.at(i) <= 'Z'))
                return false;
        }
        return true;
    }
};


int main() {
    Solution s;

    // std::cout << s.detectCapitalUse("FlaG");
    std::cout << s.detectCapitalUse("mL");

    return 0;
}
