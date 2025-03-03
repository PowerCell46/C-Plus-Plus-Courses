#include <iostream>
#include <vector>
#include <sstream>

using std::string;


class Solution {
public:
    bool isSubsequence(string possibleSubstr, string originalStr) {
        auto possibleIter = possibleSubstr.cbegin();
        auto originalIter = originalStr.cbegin();

        while (possibleIter != possibleSubstr.cend() && originalIter != originalStr.cend()) {
            if (*possibleIter == *originalIter) {
                ++possibleIter;
                ++originalIter;
            } else {
                ++originalIter;
            }
        }
        return possibleIter == possibleSubstr.cend();
    }
};


int main() {
    Solution s;

    // std::cout << s.isSubsequence("abc", "ahbgdc");
    std::cout << s.isSubsequence("axc", "ahbgdc");

    return 0;
}
