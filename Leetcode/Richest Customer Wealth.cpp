class Solution {
    static int calculateCurrentSum(std::vector<int>& currentVector) {
        return [currentVector]() -> long long {
            return std::accumulate(currentVector.begin(), currentVector.end(), 0);
        }();
    }

public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int biggestSum{};

        auto iter = accounts.begin();
        auto revIter = accounts.rbegin();

        while (iter < revIter.base() - 1) {
            biggestSum = std::max(biggestSum, calculateCurrentSum(*iter));
            biggestSum = std::max(biggestSum, calculateCurrentSum(*revIter));
            ++iter;
            ++revIter;
        }
        if (iter == revIter.base() - 1)
            biggestSum = std::max(biggestSum, calculateCurrentSum(*iter));
            

        return biggestSum;
    }
};
