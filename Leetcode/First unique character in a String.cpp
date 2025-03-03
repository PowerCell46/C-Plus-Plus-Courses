#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using std::string;


class Solution {
public:
    int firstUniqChar(string s) {
        std::map<char, int> charOccurrences; // char: index

        for (int i = 0; i < s.size(); ++i)
            ++charOccurrences[s.at(i)];

        for (int i = 0; i < s.size(); ++i)
            if (charOccurrences[s.at(i)] == 1)
                return i;

        return -1;
    }
};


int main() {
    Solution s;

    std::cout << s.firstUniqChar("leetcode");
    // std::cout << s.firstUniqChar("loveleetcode");
    // std::cout << s.firstUniqChar("aabb");
    // std::cout << s.firstUniqChar("aadadaad");

    return 0;
}
