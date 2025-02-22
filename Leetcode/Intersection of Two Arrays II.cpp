class Solution {
    static void pushBackNumberOfTimes(std::vector<int> &numbers, const int &pushNumber, const int &numberOfTimes) {
        for (int i = 0; i < numberOfTimes; ++i)
            numbers.push_back(pushNumber);
    }

public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        auto currentNum1 = nums1.begin();
        auto currentNum2 = nums2.begin();
        int currentCounter = 0;

        int previousEqualNumber = INT_MIN; // Default value

        std::vector<int> intersection;
        intersection.reserve(std::min(nums1.size(), nums2.size()));

        while (currentNum1 != nums1.end() && currentNum2 != nums2.end()) {
            if (*currentNum1 == *currentNum2) {
                if (previousEqualNumber == *currentNum1) // If the numbers are = again, increment the counter
                    currentCounter++;
                else {
                    if (previousEqualNumber != INT_MIN)
                        // In case the current numbers are =, but not = to the previous one + the there was previous intersection
                        pushBackNumberOfTimes(intersection, previousEqualNumber, currentCounter);
                    previousEqualNumber = *currentNum1;
                    currentCounter = 1;
                }
                ++currentNum1;
                ++currentNum2;
            } else {
                if (previousEqualNumber != INT_MIN) // There was some previous intersection + the current nums are not =
                    pushBackNumberOfTimes(intersection, previousEqualNumber, currentCounter);

                previousEqualNumber = INT_MIN; // Reset the equal number to the default
                currentCounter = 0; // Reset the counter

                if (*currentNum1 < *currentNum2) // If the num from the 1st is smaller, increment it
                    ++currentNum1;
                else if (*currentNum1 > *currentNum2) // If the num from the 2nd is smaller, increment it
                    ++currentNum2;
            }
        }

        if (previousEqualNumber != INT_MIN)
            // If the previous number is not the default -> it's left out and has to be added
            pushBackNumberOfTimes(intersection, previousEqualNumber, currentCounter);

        return intersection;
    }
};
