#include <iostream>
#include <vector>
#include <sstream>

using std::string;


class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontalAxis{}, verticalAxis{};

        for (const char &move: moves)
            switch (move) {
                case 'R':
                    ++horizontalAxis;
                    break;
                case 'L':
                    --horizontalAxis;
                    break;
                case 'U':
                    ++verticalAxis;
                    break;
                case 'D':
                    --verticalAxis;
                    break;
            }

        return horizontalAxis == 0 && verticalAxis == 0;
    }
};

int main() {
    Solution s;

    std::cout << s.judgeCircle("LL");

    return 0;
}
