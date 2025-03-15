#include <iostream>
#include <vector>
#include <sstream>

using std::string;

class Solution {
public:
    bool checkRecord(string s) {

        int absentCount{}, lateConsecutiveCount{};

        for (std::string::const_iterator iter = s.cbegin(); iter != s.cend(); ++iter) {
            switch (*iter) {
                case 'A':
                    ++absentCount;
                    lateConsecutiveCount = 0;
                    if (absentCount == 2)
                        return false;
                    break;
                case 'L':
                    ++lateConsecutiveCount;
                    if (lateConsecutiveCount == 3)
                        return false;
                    break;
                default:
                    lateConsecutiveCount = 0;
            }
        }
        return true;
    }
};

int main() {
    Solution s;

    // std::cout << s.checkRecord("PPALLP");
    // std::cout << s.checkRecord("PPALLL");
    std::cout << s.checkRecord("LPLPLPLPLPL");

    return 0;
}
