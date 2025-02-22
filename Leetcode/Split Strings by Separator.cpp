#include <iostream>
#include <vector>
#include <sstream>

using std::vector;
using std::string;


class Solution {
public:
    static void splitWordByACharacter(const string &word, const char separator, vector<std::string> &result) {
        std::stringstream currentWordStream{};

        for (const char &ch: word)
            if (ch == separator) {
                if (std::string currentStreamContent = currentWordStream.str(); !currentStreamContent.empty()) {
                    result.push_back(currentStreamContent);
                    currentWordStream.str("");
                }

            } else {
                currentWordStream << ch;
            }

        if (!currentWordStream.str().empty())
            result.push_back(currentWordStream.str());
    }

    vector<string> splitWordsBySeparator(vector<string> &words, char separator) {
        std::vector<std::string> resultVector;

        for (const std::string &word: words)
            splitWordByACharacter(word, separator, resultVector);

        return resultVector;
    }
};

int main() {
    Solution s;

    std::vector<std::string> words = {"one.two.three", "four.five", "six"};
    // std::vector<std::string> words = {"$easy$","$problem$"};
    // std::vector<std::string> words = {"|||"};

    auto v = s.splitWordsBySeparator(words, '.');

    for (auto basic_string: v)
        std::cout << basic_string << ' ';

    return 0;
}
