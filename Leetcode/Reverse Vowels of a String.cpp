#include <iostream>
#include <vector>
#include <sstream>
#include <set>

using std::string;


class Solution {
public:
    string reverseVowels(string s) {
        const std::set<char> vowels{'a', 'e', 'i', 'o', 'u'};

        auto iter = s.begin();
        auto revIter = s.rbegin();

        while (iter < revIter.base() - 1) {
            if (vowels.contains(std::tolower(*iter)) && vowels.contains(std::tolower(*revIter))) {
                *iter ^= *revIter;
                *revIter ^= *iter;
                *iter ^= *revIter;
                ++iter;
                ++revIter;
            } else if (vowels.contains(std::tolower(*iter)))
                ++revIter;
            else if (vowels.contains(std::tolower(*revIter)))
                ++iter;
            else {
                ++iter;
                ++revIter;
            }
        }

        return s;
    }
};


int main() {
    Solution s;

    // std::cout << s.reverseVowels("IceCreAm");
    std::cout << s.reverseVowels("leetcode");

    return 0;
}
