#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using std::vector;
using std::string;
typedef std::vector<int> intVector;
typedef std::vector<std::string> stringVector;


class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &score) {
        std::vector<int> ordered = score;
        std::sort(ordered.begin(), ordered.end());

        std::map<int, int> numPositions; // <placing, index>

        const auto orderedBeginIter = ordered.rbegin();
        for (auto iter = orderedBeginIter; iter != ordered.rend(); ++iter)
            numPositions[*iter] = (iter - orderedBeginIter) + 1;

        std::vector<std::string> placings;
        placings.reserve(score.size());

        for (auto iter = score.begin(); iter != score.end(); ++iter) {
            int currentPlacingIndex = numPositions[*iter];

            switch (currentPlacingIndex) {
                case 1: {
                    placings.push_back("Gold Medal");
                    break;
                }
                case 2: {
                    placings.push_back("Silver Medal");
                    break;
                }
                case 3: {
                    placings.push_back("Bronze Medal");
                    break;
                }
                default:
                    placings.push_back(std::to_string(currentPlacingIndex));
                    break;
            }
        }

        return placings;
    }
};


int main() {
    Solution s;

    // intVector intV{5, 4, 3, 2, 1};
    intVector intV{10, 3, 8, 9, 4};

    for (auto& find_relative_rank : s.findRelativeRanks(intV))
        std::cout << find_relative_rank << ' ';

    return 0;
}
