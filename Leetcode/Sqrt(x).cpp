#include <iostream>
#include <sstream>


class Solution {
public:
    int mySqrt(int x) {
        for (long long i = 1; i <= x / 2; ++i) {
            if (i * i == x || i * i < x && (i + 1) * (i + 1) > x)
                return i;
        }
        return x;
    }
};


int main() {
    Solution s;

    std::cout << s.mySqrt(2147483647);

    return 0;
}
