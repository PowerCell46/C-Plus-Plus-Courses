#include <iostream>
#include <vector>
#include <sstream>
#include <set>

using std::string;


#define VOWELS std::set{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}

class Solution {
public:
    string toGoatLatin(string sentence) {
        std::stringstream resultStream{};
        std::stringstream sentenceStream{sentence};

        std::string currentWord;

        int index{};
        while (sentenceStream >> currentWord) {
            if (char currentBeginChar = *currentWord.begin(); !VOWELS.contains(currentBeginChar))
                currentWord = std::string(currentWord.begin() + 1, currentWord.end()) + currentBeginChar;
            currentWord += std::string("ma") + std::string(++index, 'a');
            resultStream << currentWord << ' ';
        }

        std::string result = resultStream.str();
        return std::string(result.begin(), result.end() - 1);
    }
};

int main() {
    Solution s;

    // std::cout << s.toGoatLatin("I speak Goat Latin");
    std::cout << s.toGoatLatin("Each word consists of lowercase and uppercase letters only");

    return 0;
}
