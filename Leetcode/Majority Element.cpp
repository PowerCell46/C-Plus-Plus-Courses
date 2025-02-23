class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> numberOccurrences;

        for (const int& num : nums)
            numberOccurrences[num]++;

        for (auto& number_occurrence : numberOccurrences)
            if (number_occurrence.second > nums.size() / 2)
                return number_occurrence.first;

        return 0;
    }
};
