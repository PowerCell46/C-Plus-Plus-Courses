#include <iostream>
#include <set>
#include <map>
#include <sstream>


std::string displayCityInfo(const std::string&, const double&);

bool isCityNameCorrect(const std::string&);


int main() {
    std::string uselessLine;
    std::getline(std::cin, uselessLine);

    int numberOfCities;
    std::stringstream numberOfCitiesStream{uselessLine};
    numberOfCitiesStream >> numberOfCities;

    std::set<std::string> cityNames;
    std::map<std::string, double> cityMap;

    while (true) {
        std::string currentLine, currentCity;
        std::getline(std::cin, currentLine);

        if (currentLine.empty() || !isCityNameCorrect(currentCity))
            break;

        std::stringstream lineStream{currentLine};
        lineStream >> currentCity;

        double productPrice;
        int productQuantity;

        std::getline(std::cin, currentLine);
        lineStream = std::stringstream{currentLine};
        lineStream >> productPrice;

        std::getline(std::cin, currentLine);
        lineStream = std::stringstream{currentLine};
        lineStream >> productQuantity;

        cityMap[currentCity] += productPrice * productQuantity;
        cityNames.insert(currentCity);

        if (numberOfCities == 1)
            break;
    }

    for (const std::string& cityName : cityNames)
        std::cout << displayCityInfo(cityName, cityMap[cityName]);

    return 0;
}


std::string displayCityInfo(const std::string& cityName, const double& totalCost) {
    std::stringstream resultStream{};

    resultStream << cityName << ' ' << totalCost << '\n';

    return resultStream.str();
}


bool isCityNameCorrect(const std::string& cityName) {
    for (const char& ch : cityName)
        if (std::isdigit(ch) || ch == '.')
            return false;
    return true;
}
