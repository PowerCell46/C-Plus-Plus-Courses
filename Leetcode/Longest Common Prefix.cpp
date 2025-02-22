#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using std::vector;
using std::string;


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        std::vector<char> longestPrefix;

        const auto minLengthStr = std::min_element(
            strs.begin(),
            strs.end(),
            [](const std::string &strA, const std::string &strB) { return strA.size() < strB.size(); }
        );

        if (minLengthStr == strs.end())
            return "";

        longestPrefix.reserve(minLengthStr->size());
        for (int i = 0; i < minLengthStr->size(); ++i)
            longestPrefix.push_back(minLengthStr->at(i));


        for (int i = 0; i < strs.size(); ++i) {
            const std::string currentStr = strs.at(i);

            for (int j = 0; j < std::min(currentStr.size(), longestPrefix.size()); ++j) {
                if (currentStr.at(j) != longestPrefix.at(j)) {
                    if (j == 0)
                        return "";

                    const std::vector<char> sliced{longestPrefix.begin(), longestPrefix.begin() + j};
                    longestPrefix = sliced;
                }
            }
        }

        std::stringstream resultStream{};
        for (int i = 0; i < longestPrefix.size(); ++i)
            resultStream << longestPrefix.at(i);

        return resultStream.str();
    }
};

int main() {
    Solution s;

    // std::vector<std::string> strs{"flower","flow","flight"};
    // std::vector<std::string> strs{"dog","racecar","car"};
    // std::vector<std::string> strs{"ab", "a"};
    std::vector<std::string> strs{"reflower", "flow", "flight"};


    std::cout << s.longestCommonPrefix(strs);

    return 0;
}
