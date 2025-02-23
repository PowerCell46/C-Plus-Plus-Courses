#include <iostream>
#include <vector>
#include <sstream>

using std::string;


class Solution {
public:
    int strStr(string haystack, string needle) {
        const auto haystackBegin = haystack.begin();
        const auto substrIter = needle.begin();

        for (auto strIter = haystackBegin; strIter != haystack.end(); ++strIter) {
                if (*strIter == *substrIter && strIter - haystackBegin + needle.size() <= haystack.size()) {
                    const std::string foundSubstr{strIter, strIter + needle.size()};

                    if (foundSubstr == needle)
                        return strIter - haystackBegin;
                }
        }

        return -1;
    }
};


int main() {
    Solution s;

    std::cout << s.strStr("sadbutsad", "sad");

    return 0;
}
