#include <iostream>
#include <vector>
#include <sstream>

using std::string;


class Solution {
public:
    string toLowerCase(string s) {
        std::stringstream resultStream{};

        for (const char& ch : s)
            resultStream << static_cast<char>((ch >= 65 && ch <= 90) ? ch + 32 : ch);

        return resultStream.str();
    }
};


int main() {
    Solution s;

    std::cout << s.toLowerCase("Hello");

    return 0;
}
