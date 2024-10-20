#include <iostream>


int main() {
    double cpuPriceInDollars, videocardPriceInDollars, ramPriceInDollars, discountPercentage, DOLLAR_TO_LEV_RATIO =
            1.57;
    int numberOfRams;

    std::cin >> cpuPriceInDollars >> videocardPriceInDollars >> ramPriceInDollars >> numberOfRams >> discountPercentage;

    double totalSumInLevs = (
                                (cpuPriceInDollars - cpuPriceInDollars * discountPercentage) +
                                (videocardPriceInDollars - videocardPriceInDollars * discountPercentage) +
                                (ramPriceInDollars * numberOfRams)
                            )
                            * DOLLAR_TO_LEV_RATIO;

    printf("Money needed - %.2f leva.", totalSumInLevs);

    return 0;
}
