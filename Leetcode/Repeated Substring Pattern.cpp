#include <iostream>
#include <vector>
#include <sstream>

using std::string;


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (auto iter = s.begin(); iter != s.end() - 1; ++iter) {
            const std::string sSubstr = std::string{s.begin(), iter + 1};
            std::string finalSubstr = sSubstr;

            while (finalSubstr.length() < s.length())
                finalSubstr += sSubstr;
            if (finalSubstr == s)
                return true;
        }

        return false;
    }
};


int main() {
    Solution s;

    std::cout << s.repeatedSubstringPattern("abcabcabcabc");

    return 0;
}
