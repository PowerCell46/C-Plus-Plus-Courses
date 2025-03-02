#include <iostream>
#include <numeric>
#include <vector>
#include <sstream>

using std::vector;
using std::string;


class Solution {
public:
    int calPoints(vector<string> &operations) {
        std::vector<int> record;
        record.reserve(operations.size());

        for (std::string &operation: operations) {
            if (operation == "+" && record.size() > 1)
                record.push_back(*(record.end() - 1) + *(record.end() - 2));

            else if (operation == "D" && !record.empty())
                record.push_back(*(record.end() - 1) * 2);

            else if (operation == "C" && !record.empty())
                record.pop_back();

            else
                record.push_back(std::stoi(operation));
        }

        return [record]() -> int {
            return std::accumulate(record.begin(), record.end(), 0);
        }();
    }
};

int main() {
    Solution s;

    // std::vector<std::string> operations{"5","2","C","D","+"};
    std::vector<std::string> operations{"5", "-2", "4", "C", "D", "9", "+", "+"};

    std::cout << s.calPoints(operations);

    return 0;
}
