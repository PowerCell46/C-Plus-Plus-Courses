#include <iostream>
#include <vector>
#include <sstream>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<std::string> result;
        result.reserve(n);

        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0)
                result.push_back("FizzBuzz");
            else if (i % 3 == 0)
                result.push_back("Fizz");
            else if (i % 5 == 0)
                result.push_back("Buzz");
            else
                result.push_back(std::to_string(i));
        }

        return result;
    }
};

int main() {
    Solution s;

    for (auto fizz_buzz : s.fizzBuzz(3))
        std::cout << fizz_buzz << ' ';

    return 0;
}
