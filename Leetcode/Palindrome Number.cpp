#include <iostream>
#include <vector>
#include <sstream>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string strX = std::to_string(x);

        auto iter = strX.begin();
        auto rIter = strX.rbegin();

        while (iter != strX.end() && rIter != strX.rend()) {
            if (*iter != *rIter)
                return false;
            if (rIter.base() - 1 == iter)
                return true;

            ++iter;
            ++rIter;
        }

        return true;
    }
};

int main() {

    Solution s;

    std::cout << s.isPalindrome(1201);

    return 0;
}
