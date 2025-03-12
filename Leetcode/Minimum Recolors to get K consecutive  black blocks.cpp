#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using std::string;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minNumberOfWhiteBlocks = INT_MAX;
        int whiteBlocksCount{};

        for (auto iter = blocks.begin(); iter != blocks.begin() + k - 1; ++iter) {
            whiteBlocksCount += *iter == 'W';
        }

        for (auto iter = blocks.begin(); iter != blocks.end() - k + 1; ++iter) {
            whiteBlocksCount += *(iter + k - 1) == 'W';
            minNumberOfWhiteBlocks = std::min(minNumberOfWhiteBlocks, whiteBlocksCount);
            whiteBlocksCount -= *iter == 'W';
        }

        return minNumberOfWhiteBlocks;
    }
};

int main() {
    Solution s;

    // std::cout << s.minimumRecolors("WBBWWBBWBW", 7);
    // std::cout << s.minimumRecolors("WBB", 1);
    std::cout << s.minimumRecolors("WBB", 1);

    return 0;
}
