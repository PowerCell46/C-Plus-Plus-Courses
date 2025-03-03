#include <iostream>
#include <vector>
#include <sstream>

using std::string;


class Solution {
public:
    int countSegments(string s) {
        int count{};

        std::stringstream currentSequence{};
        for (const char& ch : s) {
            if (ch != ' ')
                currentSequence << ch;
            else
                if (!currentSequence.str().empty()) {
                    ++count;
                    currentSequence.str("");
                }
        }
        if (!currentSequence.str().empty())
            ++count;

        return count;
    }
};


int main() {
    Solution s;

    // std::cout << s.countSegments("Hello, my name is John");
    std::cout << s.countSegments("Hello");

    return 0;
}
