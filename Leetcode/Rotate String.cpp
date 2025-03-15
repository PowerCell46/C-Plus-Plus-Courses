#include <iostream>
#include <vector>
#include <sstream>

using std::string;


class Solution {
public:
    bool rotateString(string s, string goal) {
        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            if (*iter == *goal.begin()) {
                if (std::string(iter, s.end()) + std::string(s.begin(), iter) == goal)
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;

    // std::cout << s.rotateString("abcde", "cdeab");
    std::cout << s.rotateString("abcde", "abced");

    return 0;
}
