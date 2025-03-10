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

/*
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int biggestStockProfit = 0;

        if (prices.size() == 1)
            return biggestStockProfit;

        auto mostExpensiveStockPrice = std::max_element(prices.begin(), prices.end());

        auto cheapestPriceBeforeBiggestPrice = std::min_element(prices.begin(), mostExpensiveStockPrice);

        if (cheapestPriceBeforeBiggestPrice != prices.end())
            biggestStockProfit = std::max(*mostExpensiveStockPrice - *cheapestPriceBeforeBiggestPrice,
                                          biggestStockProfit);


        auto cheapestStockPrice = std::min_element(prices.begin(), prices.end());

        auto highestPriceAfterSmallestPrice = std::max_element(cheapestStockPrice + 1, prices.end());

        if (highestPriceAfterSmallestPrice != prices.end())
            biggestStockProfit = std::max(*highestPriceAfterSmallestPrice - *cheapestStockPrice, biggestStockProfit);


        if (mostExpensiveStockPrice + 1 != prices.end() && mostExpensiveStockPrice < cheapestStockPrice) {
            std::vector<int> slicedVector(mostExpensiveStockPrice + 1, cheapestStockPrice);

            for (int i = 0; i < slicedVector.size(); ++i)
                for (int j = i + 1; j < slicedVector.size(); ++j)
                    if (const int currentMadeProfit = slicedVector.at(j) - slicedVector.at(i);
                        currentMadeProfit > biggestStockProfit)
                        biggestStockProfit = currentMadeProfit;
        }

        return biggestStockProfit;
    }
};
*/
