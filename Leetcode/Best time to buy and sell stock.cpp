class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int biggestStockProfit = 0;

        while (prices.size() > 1) {
            // finding the most expensive Stock price
            auto mostExpensiveStockPrice = --std::max_element(prices.rbegin(), prices.rend()).base();

            // find the cheapest price the days before the most expensive price
            auto cheapestPriceBeforeBiggestPrice = std::min_element(prices.begin(), mostExpensiveStockPrice);

            if (cheapestPriceBeforeBiggestPrice != prices.end())
                biggestStockProfit = std::max(*mostExpensiveStockPrice - *cheapestPriceBeforeBiggestPrice,
                                              biggestStockProfit);


            // find the cheapest Stock price
            auto cheapestStockPrice = std::min_element(prices.begin(), prices.end());

            auto highestPriceAfterSmallestPrice = std::max_element(cheapestStockPrice + 1, prices.end());

            // find the most expensive price the days after the most expensive price
            if (highestPriceAfterSmallestPrice != prices.end())
                biggestStockProfit = std::max(*highestPriceAfterSmallestPrice - *cheapestStockPrice,
                                              biggestStockProfit);


            std::vector<int> slicedVector(std::min(mostExpensiveStockPrice, cheapestStockPrice) + 1,
                                          std::max(mostExpensiveStockPrice, cheapestStockPrice));
            prices = slicedVector;
        }

        return biggestStockProfit;
    }
};
