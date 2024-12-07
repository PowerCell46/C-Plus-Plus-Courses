#include <iostream>
#include <vector>
#include <sstream>
#include <map>


std::string joinStringVector(const std::vector<std::string>& stringVector) {
    std::stringstream resultStream{};

    for (int i = 0; i < stringVector.size(); ++i) {
        resultStream << stringVector.at(i);
        if (i < stringVector.size() - 1)
            resultStream << ',';
        resultStream << ' ';
    }

    return resultStream.str();
}


int main() {
    std::map<std::string, std::map<std::string, std::vector<std::string>>> continentsCountriesCitiesMap;
    std::vector<std::string> continentsOrderVector;
    std::map<std::string, std::vector<std::string>> countriesOrderMap;

    int numberOfInputs;
    std::cin >> numberOfInputs;
    std::cin.ignore();

    for (int i = 0; i < numberOfInputs; ++i) {
        std::string currentLine, currentContinent, currentCountry, currentCity;
        std::getline(std::cin, currentLine);
        std::stringstream lineStream{currentLine};

        lineStream >> currentContinent >> currentCountry >> currentCity;

        if (continentsCountriesCitiesMap.find(currentContinent) == continentsCountriesCitiesMap.end()) {
            std::map<std::string, std::vector<std::string>> currentCountryMap;
            currentCountryMap.insert({currentCountry, std::vector<std::string>{currentCity}});

            continentsCountriesCitiesMap.insert({currentContinent, currentCountryMap});

            continentsOrderVector.push_back(currentContinent);
            countriesOrderMap.insert({currentContinent, std::vector<std::string>{}});

            countriesOrderMap.find(currentContinent)->second.push_back(currentCountry);


        } else if (continentsCountriesCitiesMap.find(currentContinent)->second.find(currentCountry) == continentsCountriesCitiesMap.find(currentContinent)->second.end()) {
            continentsCountriesCitiesMap
                .find(currentContinent)->second.insert({currentCountry, std::vector<std::string>{currentCity}});

            countriesOrderMap.find(currentContinent)->second.push_back(currentCountry);

        } else
            continentsCountriesCitiesMap.find(currentContinent)->second.find(currentCountry)->second.push_back(currentCity);
    }

    std::stringstream resultStream{};
    for (const std::string& continentName : continentsOrderVector) {
        resultStream << continentName << ':' << '\n';

        for (const std::string& countryName : countriesOrderMap.find(continentName)->second) {
            resultStream << "  " << countryName << " -> ";

            resultStream << joinStringVector(continentsCountriesCitiesMap.find(continentName)->second.find(countryName)->second) << '\n';
        }
    }

    std::cout << resultStream.str();

    return 0;
}

// 9
// Europe Bulgaria Sofia
// Asia China Beijing
// Asia Japan Tokyo
// Europe Poland Warsaw
// Europe Germany Berlin
// Europe Poland Poznan
// Europe Bulgaria Plovdiv
// Africa Nigeria Abuja
// Asia China Shanghai
