#include <iostream>


int main() {
    int numberOfDays;
    double totalLiters = 0, totalDegrees = 0, averageDegrees;

    std::cin >> numberOfDays;

    for (int i = 0; i < numberOfDays; ++i) {
        double rakijaQuantity, degrees;
        std::cin >> rakijaQuantity >> degrees;

        totalLiters += rakijaQuantity;
        totalDegrees += degrees * rakijaQuantity;
    }

    printf("Liter: %.2f\n", totalLiters);
    averageDegrees = totalDegrees / totalLiters;
    printf("Degrees: %.2f\n", averageDegrees);

    averageDegrees < 38
        ? printf("Not good, you should baking!")
        : (averageDegrees <= 42
               ? printf("Super!")
               : printf("Dilution with distilled water!"));


    return 0;
}
