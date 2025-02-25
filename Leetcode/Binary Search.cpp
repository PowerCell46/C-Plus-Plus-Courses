class Solution {
public:
    int search(vector<int> &nums, int target) {
        int index{};

        while (!nums.empty()) {
            auto numsBegin = nums.begin();
            const int halfIndex = nums.size() / 2;

            const int currentNumber = nums.at(halfIndex);

            if (currentNumber == target)
                return index + halfIndex;

            if (currentNumber > target)
                nums.erase(numsBegin + halfIndex, nums.end());

            else {
                index += halfIndex + 1;
                nums.erase(numsBegin, numsBegin + halfIndex + 1);
            }
        }
        return -1;
    }
};
