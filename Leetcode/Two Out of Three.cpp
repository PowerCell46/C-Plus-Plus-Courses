#include <iostream>
#include <vector>
#include <set>

using std::vector;

class Solution {
    static void checkIfSetContainsAndRemove(const int& element, std::set<int>& result, std::set<int>& searchSet) {
        if (searchSet.contains(element)) {
            result.insert(element);
            searchSet.erase(element);
        }
    }
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3) {
        std::set<int> firstSet{nums1.begin(), nums1.end()};
        std::set<int> secondSet{nums2.begin(), nums2.end()};
        std::set<int> thirdSet{nums3.begin(), nums3.end()};

        std::set<int> result;

        for (const int &currentElement: firstSet) {
            checkIfSetContainsAndRemove(currentElement, result, secondSet);
            checkIfSetContainsAndRemove(currentElement, result, thirdSet);
        }

        for (const int &currentElement: secondSet) {
            checkIfSetContainsAndRemove(currentElement, result, thirdSet);
        }

        return std::vector<int>{result.begin(), result.end()};
    }
};

int main() {
    Solution s;
    // std::vector<int> first{1, 1, 3, 2}, second{2, 3}, third{3};
    std::vector<int> first{3, 1}, second{2, 3}, third{1, 2};

    auto v = s.twoOutOfThree(first, second, third);

    for (int v1: v)
        std::cout << v1 << ' ';

    return 0;
}
