#include <iostream>


int main() {
    double shirtPrice, goalSum, shortsPrice, socksPrice, shoesPrice, neededAmountOfMoney;

    std::cin >> shirtPrice >> goalSum;

    shortsPrice = shirtPrice * 0.75;
    socksPrice = shortsPrice * 0.2;
    shoesPrice = (shirtPrice + shortsPrice) * 2;

    neededAmountOfMoney = shirtPrice + shortsPrice + socksPrice + shoesPrice;
    neededAmountOfMoney *= 0.85;

    if (neededAmountOfMoney >= goalSum)
        printf("Yes, he will earn the world-cup replica ball!\nHis sum is %.2f lv.", neededAmountOfMoney);
    else
        printf("No, he will not earn the world-cup replica ball.\nHe needs %.2f lv. more.", goalSum - neededAmountOfMoney);


    return 0;
}
