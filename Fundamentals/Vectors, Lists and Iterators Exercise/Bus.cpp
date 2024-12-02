#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;


int parseHourAndMinutesToMinutes(const std::string& timeStr) { // 2205 -> 22:05 = 22 * 60 + 05;
    return std::stoi(timeStr.substr(0, 2)) * 60 + std::stoi(timeStr.substr(2, 4));
}


int main() {
    int numberOfBuses;
    std::cin >> numberOfBuses;

    int* buses = new int[numberOfBuses];

    for (int i = 0; i < numberOfBuses; ++i) {
        std::string currentNumberStr;
        std::cin >> currentNumberStr;
        buses[i] = parseHourAndMinutesToMinutes(currentNumberStr);
    }

    std::string departureTimeStr;
    std::cin >> departureTimeStr;
    int departureTime = parseHourAndMinutesToMinutes(departureTimeStr);


    int smallestDiff = 1'000'000, busNumber = 0;

    for (int i = 0; i < numberOfBuses; ++i) {
        if (buses[i] > departureTime) // bus arrival is after the departure time
            continue;

        if (departureTime - buses[i] < smallestDiff) { // if current diff < smallest diff
            smallestDiff = departureTime - buses[i];
            busNumber = i + 1;
        }
    }

    std::cout << busNumber << std::endl;

    delete[] buses;

    return 0;
}
