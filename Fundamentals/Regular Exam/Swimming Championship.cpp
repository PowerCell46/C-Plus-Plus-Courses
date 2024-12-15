#include <iostream>
#include <sstream>
#define PRINT_STRING_RESULT_TEMPLATE std::string("Money left to pay: %.2f BGN.\nThe championship was ")


int main() {
    int numberOfDays, neededPoints, numberOfSwimmers;
    double hotelRoomPricePerSwimmer, participationFeePerSwimmer;

    std::cin >> numberOfDays >> neededPoints >> numberOfSwimmers
            >> hotelRoomPricePerSwimmer >> participationFeePerSwimmer;


    double totalExpenses = 0;
    totalExpenses += numberOfDays * numberOfSwimmers * hotelRoomPricePerSwimmer;
    totalExpenses += participationFeePerSwimmer * numberOfSwimmers;


    double earnedPoints = 0, previousDayPoints;
    for (int i = 0; i < numberOfDays; ++i) {
        double currentDayEarnedPoints;
        std::cin >> currentDayEarnedPoints;

        earnedPoints += currentDayEarnedPoints;
        if (i != 0)
            earnedPoints += previousDayPoints * 0.05;
        previousDayPoints = currentDayEarnedPoints;
    }


    if (earnedPoints >= neededPoints) {
        totalExpenses *= 0.75;
        printf((PRINT_STRING_RESULT_TEMPLATE + std::string("successful!")).c_str(), totalExpenses);

    } else {
        totalExpenses *= 0.9;
        printf((PRINT_STRING_RESULT_TEMPLATE + std::string("not successful.")).c_str(), totalExpenses);
    }

    return 0;
}
