#include <iostream>
#include <set>
#include <vector>
#include <sstream>

using std::vector;
using std::string;

class Solution {
    static std::string convertWordToMorseCode(const std::string& word) {
        const std::vector<std::string> morseCodeMapper{
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
            "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
            "..-","...-",".--","-..-","-.--","--.."
        };

        std::stringstream resultWordStream{};
        for (const char& ch : word)
            resultWordStream << morseCodeMapper[std::tolower(ch) - 'a'];

        return resultWordStream.str();
    }
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        std::set<std::string> resultWords;

        for (const std::string& word : words)
            resultWords.insert(convertWordToMorseCode(word));

        return resultWords.size();
    }
};

int main() {
    Solution s;

    std::vector<std::string> strings = {"gin","zen","gig","msg"};

    std::cout << s.uniqueMorseRepresentations(strings);
    return 0;
}
