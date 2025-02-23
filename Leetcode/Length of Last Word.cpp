#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
using std::string;

class Solution {
public:
    int lengthOfLastWord(string s) {
        std::stack<std::string> wordsStack{};

        std::stringstream strStream{s};
        std::string currentWord;
        while (strStream >> currentWord)
            wordsStack.push(currentWord);

        return wordsStack.top().size();
    }
};


int main() {
    Solution s;

    // std::cout << s.lengthOfLastWord( "Hello World");
    std::cout << s.lengthOfLastWord( "   fly me   to   the moon  ");

    return 0;
}
