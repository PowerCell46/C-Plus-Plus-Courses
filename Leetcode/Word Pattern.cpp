#include <iostream>
#include <map>
#include <set>
#include <sstream>

using std::string;


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::string* stringArr = new std::string[pattern.length()];

        std::stringstream strStream{s};
        std::string currentWord;
        for (int i = 0;; ++i) {
            if (strStream >> currentWord) {
                if (i == pattern.size()) {
                    delete[] stringArr;
                    return false;
                }
                stringArr[i] = currentWord;
            }
            else {
                if (i < pattern.size()) {
                    delete[] stringArr;
                    return false;
                }
                break;
            }
        }

        std::map<char, std::string> mapper;
        std::set<std::string> usedWords;

        const auto patternBegin = pattern.begin();

        for (auto iter = patternBegin; iter != pattern.end(); ++iter) {
            const int currentIndex = iter - pattern.begin();

            if (!mapper.contains(*iter)) {
                if (usedWords.contains(stringArr[currentIndex])) {
                    delete[] stringArr;
                    return false;
                }
                mapper[*iter] = stringArr[currentIndex];
                usedWords.insert(stringArr[currentIndex]);

            } else {
                if (mapper[*iter] != stringArr[currentIndex]) {
                    delete[] stringArr;
                    return false;
                }
            }
        }

        delete[] stringArr;
        return true;
    }
};


int main() {
    Solution s;

    // std::cout << s.wordPattern("abba", "dog cat cat dog");
    // std::cout << s.wordPattern("abba", "dog cat cat fish");
    // std::cout << s.wordPattern("aaaa", "dog cat cat dog");
    // std::cout << s.wordPattern("aba", "cat cat cat dog");
    std::cout << s.wordPattern("he", "unit");

    return 0;
}
