#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using std::vector;
using std::string;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::string, std::vector<std::string>> occurrences;

        for (const std::string& currentStr : strs) {
            std::map<char, int> letterOccurrences;

            for (const char& ch : currentStr)
                letterOccurrences[ch]++;

            std::stringstream currentOccurrencesStream{};
            for (std::pair<const char, int>& letterOccurrence : letterOccurrences)
                currentOccurrencesStream << letterOccurrence.first << letterOccurrence.second;

            occurrences[currentOccurrencesStream.str()].push_back(currentStr);
        }

        std::vector<std::vector<std::string>> answers;
        for (const std::pair<const string, vector<string>>& occurrence : occurrences)
            answers.push_back(occurrence.second);

        return answers;
    }
};


int main() {
    Solution s;

    std::vector<std::string> words{"eat","tea","tan","ate","nat","bat"};

    for (vector<string>& basicStrings : s.groupAnagrams(words)) {
        for (string& basicString : basicStrings)
            std::cout << basicString << ' ';
        std::cout << '\n';
    }

    return 0;
}
