class Solution {
public:
    int thirdMax(vector<int>& nums) {
        std::set<int> uniqueNumbers{nums.begin(), nums.end()};

        return uniqueNumbers.size() > 2 ?
            *(++++uniqueNumbers.rbegin()) : *uniqueNumbers.rbegin();
    }
};
