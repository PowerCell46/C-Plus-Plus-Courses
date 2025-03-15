#include <iostream>
#include <list>
#include <sstream>

using std::string;


class Solution {
public:
    string reverseWords(string s) {
        std::list<std::string> words;

        std::stringstream sStream{s};
        std::string currentWord;
        while (sStream >> currentWord)
            words.push_front(currentWord);

        std::stringstream resultStream{};
        for (string& word : words)
            resultStream << word << ' ';

        std::string result = resultStream.str();
        return std::string(result.begin(), result.end() - 1);
    }
};


int main() {
    Solution s;

    // std::cout << s.reverseWords("  hello world  ");
    std::cout << s.reverseWords("the sky is blue");

    return 0;
}
