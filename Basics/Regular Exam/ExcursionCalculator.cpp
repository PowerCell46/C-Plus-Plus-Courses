#include <iostream>


int main() {
    int numberOfPeople;
    double pricePerPerson = 0;
    std::string season;

    std::cin >> numberOfPeople >> season;


    if (season == "spring") {

        if (numberOfPeople <= 5)
            pricePerPerson = 50;
        else
            pricePerPerson = 48;

    } else if (season == "summer") {

        if (numberOfPeople <= 5)
            pricePerPerson = 48.50;
        else
            pricePerPerson = 45;

        pricePerPerson *= 0.85;

    } else if (season == "autumn") {

        if (numberOfPeople <= 5)
            pricePerPerson = 60;
        else
            pricePerPerson = 49.50;

    } else if (season == "winter") {

        if (numberOfPeople <= 5)
            pricePerPerson = 86;
        else
            pricePerPerson = 85;

        pricePerPerson *= 1.08;
    }

    printf("%.2f leva.", pricePerPerson * numberOfPeople);

    return 0;
}
