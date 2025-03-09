#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <map>

using std::string;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> usedChars;
        std::stringstream wordStream{};
        int maxLength{};
        auto mainIter = s.begin();

        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            char ch = *iter;
            if (usedChars.contains(ch)) {
                if (const int currentSize = wordStream.str().size(); currentSize > maxLength)
                    maxLength = currentSize;
                wordStream.str("");
                usedChars.clear();
                iter = (++mainIter);
                --iter;
                continue;
            }

            usedChars.insert(ch);
            wordStream << ch;
        }
        if (const int currentSize = wordStream.str().size(); currentSize > maxLength)
            maxLength = currentSize;

        return maxLength;
    }
};

int main() {
    Solution s;

    std::cout << s.lengthOfLongestSubstring("dvdf");

    return 0;
}
