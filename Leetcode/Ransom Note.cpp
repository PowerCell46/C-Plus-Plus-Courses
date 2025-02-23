#include <iostream>
#include <map>
#include <sstream>

using std::string;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::map<char, int> ransomOccurrences;
        std::map<char, int> magazineOccurrences;

        for (const char& ch : ransomNote)
            ransomOccurrences[ch]++;
        for (const char& ch : magazine)
            magazineOccurrences[ch]++;

        for (auto& ransom_occurrence : ransomOccurrences) {
            if (!magazineOccurrences.contains(ransom_occurrence.first))
                return false;
            if (magazineOccurrences[ransom_occurrence.first] < ransom_occurrence.second)
                return false;
        }

        return true;
    }
};


int main() {
    Solution s;

    // std::cout << s.canConstruct("a", "b");
    // std::cout << s.canConstruct("aa", "ab");
    std::cout << s.canConstruct("aa", "aab");

    return 0;
}
