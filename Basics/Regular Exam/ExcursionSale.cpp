#include <iostream>


int main() {
    int numberOfSeaExcursions, numberOfMountainExcursions, totalSum = 0,
            seaExcursionPrice = 680, mountainExcursionPrice = 499;

    std::cin >> numberOfSeaExcursions >> numberOfMountainExcursions;

    do {
        std::string currentInput;
        std::cin >> currentInput;
        if (currentInput == "Stop")
            break;
        if (currentInput == "sea")
            if (numberOfSeaExcursions > 0) {
                numberOfSeaExcursions--;
                totalSum += seaExcursionPrice;
            }
        if (currentInput == "mountain")
            if (numberOfMountainExcursions > 0) {
                numberOfMountainExcursions--;
                totalSum += mountainExcursionPrice;
            }
        if (numberOfMountainExcursions == 0 && numberOfSeaExcursions == 0)
            break;

    } while (true);

    if (numberOfMountainExcursions == 0 && numberOfSeaExcursions == 0)
        std::cout << "Good job! Everything is sold.\n";
    std::cout << "Profit: " << totalSum << " leva.";


    return 0;
}
