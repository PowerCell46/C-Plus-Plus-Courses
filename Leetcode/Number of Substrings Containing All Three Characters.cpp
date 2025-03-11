#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using std::string;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int numberOfValidSubstrings{};

        std::map<char, int> charOccurrences{
            {'a', 0},
            {'b', 0},
            {'c', 0}
        };
        charOccurrences[*s.begin()]++;

        auto substrBeginIter = s.begin();
        auto substrEndIter = s.begin() + 1;

        while (substrBeginIter != s.end() - 2) {
            while (substrEndIter != s.end()) {
                if (charOccurrences['a'] > 0 && charOccurrences['b'] > 0 && charOccurrences['c'] > 0) {
                    break;
                }
                charOccurrences[*substrEndIter]++;
                ++substrEndIter;
            }
            if (charOccurrences['a'] > 0 && charOccurrences['b'] > 0 && charOccurrences['c'] > 0) {
                numberOfValidSubstrings += s.end() - substrEndIter + 1;
            }

            charOccurrences[*substrBeginIter]--;
            ++substrBeginIter;
        }

        return numberOfValidSubstrings;
    }
};

int main() {
    Solution s;

    // std::cout << s.numberOfSubstrings("abcabc");
    std::cout << s.numberOfSubstrings("aaacb");

    return 0;
}
