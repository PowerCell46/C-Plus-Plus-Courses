#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using std::string;
using std::vector;


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        std::map<char, std::vector<std::string>> firstLetterMap;

        for (const std::string& word : dictionary)
            firstLetterMap[*word.begin()].push_back(word);

        for (const std::pair<const char, vector<string>>& letterMap : firstLetterMap)
            std::sort(letterMap.second.begin(), letterMap.second.end(), [](const std::string& str1, const std::string& str2) {
               return str1.length() < str2.length();
            });

        std::stringstream sentenceStream{sentence};
        std::stringstream resultStream{};

        std::string currentWord;
        while (sentenceStream >> currentWord) {
            if (firstLetterMap.contains(*currentWord.begin())) {
                bool found = false;
                for (const std::string& str : firstLetterMap[*currentWord.begin()]) {
                    if (str == std::string(currentWord.begin(), currentWord.begin() + str.length())) {
                        resultStream << str << ' ';
                        found = true;
                        break;
                    }
                }
                if (found)
                    continue;
            }
            resultStream << currentWord << ' ';
        }

        std::string resultStr = resultStream.str();
        return std::string(resultStr.begin(), resultStr.end() - 1);
    }
};


int main() {
    Solution s;

    // std::vector<std::string> words{"cat","bat","rat"};
    // std::vector<std::string> words{"a","b","c"};
    // std::vector<std::string> words{"cat","bat","rat"};
    std::vector<std::string> words{"catt","cat","bat","rat"};

    // std::cout << s.replaceWords(words, "aadsfasf absbs bbab cadsfafs");
    // std::cout << s.replaceWords(words, "the cattle was rattled by the battery");
    std::cout << s.replaceWords(words, "the cattle was rattled by the battery");

    return 0;
}
