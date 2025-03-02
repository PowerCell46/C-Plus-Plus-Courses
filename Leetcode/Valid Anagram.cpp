#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using std::string;


class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char, int> firstStrOccurrences;
        for (const char& ch : s)
            firstStrOccurrences[ch]++;

        for (const char& ch : t)
            firstStrOccurrences[ch]--;

        for (const auto& firstStrOccurrence : firstStrOccurrences)
            if (firstStrOccurrence.second != 0)
                return false;
        return true;
    }
};


int main() {
    Solution s;

    std::cout << s.isAnagram("ab", "a");


    return 0;
}
