class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::set<int> numbersSet;
        for (int i = 0; i < nums.size(); ++i)
            numbersSet.insert(i + 1);

        for (auto iter = nums.begin(); iter != nums.end(); ++iter)
            numbersSet.erase(*iter);

        return std::vector<int>{numbersSet.begin(), numbersSet.end()};
    }
};
