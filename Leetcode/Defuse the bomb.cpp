#include <iostream>
#include <vector>
#include <sstream>

using std::vector;


class Solution {
    static int calculateRightSum(const std::vector<int> &numbersVector, const int currentIndex, int numbersCount) {
        int result{};

        for (int i = currentIndex + 1; i < numbersVector.size(); ++i) {
            result += numbersVector.at(i);
            numbersCount--;
            if (numbersCount == 0)
                return result;
        }

        while (numbersCount > 0) {
            for (int i = 0; i < numbersVector.size(); ++i) {
                result += numbersVector.at(i);
                numbersCount--;
                if (numbersCount == 0)
                    return result;
            }
        }

        return result;
    }

    static int calculateLeftSum(const std::vector<int> &numbersVector, const int currentIndex, int numbersCount) {
        numbersCount *= -1;
        int result{};

        for (int i = currentIndex - 1; i > -1; --i) {
            result += numbersVector.at(i);
            numbersCount--;
            if (numbersCount == 0)
                return result;
        }

        while (numbersCount > 0) {
            for (int i = numbersVector.size() - 1; i > -1; --i) {
                result += numbersVector.at(i);
                numbersCount--;
                if (numbersCount == 0)
                    return result;
            }
        }

        return result;
    }

public:
    vector<int> decrypt(vector<int> &code, int k) {
        std::vector<int> resultVector;
        resultVector.reserve(code.size());

        for (int i = 0; i < code.size(); ++i) {
            if (k > 0)
                resultVector.push_back(calculateRightSum(code, i, k));

            else if (k < 0)
                resultVector.push_back(calculateLeftSum(code, i, k));

            else
                resultVector.push_back(0);
        }

        return resultVector;
    }
};

int main() {
    // std::vector<int> nums{5, 7, 1, 4};
    // std::vector<int> nums{1,2,3,4};
    std::vector<int> nums{2,4,9,3};

    Solution s;

    for (int decrypt: s.decrypt(nums, -2))
        std::cout << decrypt << ' ';

    return 0;
}
