#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>


std::string joinAmdOrderStringVector(std::vector<std::string> &stringVector);


int main() {
    std::map<std::string, std::map<std::string, std::vector<std::string> > > continentsCountriesCitiesMap;

    int numberOfInputs;
    std::cin >> numberOfInputs;
    std::cin.ignore();

    for (int i = 0; i < numberOfInputs; ++i) {
        std::string currentLine, currentContinent, currentCountry, currentCity;
        std::getline(std::cin, currentLine);
        std::stringstream lineStream{currentLine};

        lineStream >> currentContinent >> currentCountry >> currentCity;

        if (continentsCountriesCitiesMap.find(currentContinent) == continentsCountriesCitiesMap.end()) {

            std::map<std::string, std::vector<std::string> > currentCountryMap;

            currentCountryMap.insert({currentCountry, std::vector<std::string>{currentCity}});

            continentsCountriesCitiesMap.insert({currentContinent, currentCountryMap});
            
        } else if (continentsCountriesCitiesMap.find(currentContinent)->second.find(currentCountry) == continentsCountriesCitiesMap.find(currentContinent)->second.end()) {

            continentsCountriesCitiesMap
                .find(currentContinent)->second.insert({currentCountry, std::vector<std::string>{currentCity}});

        } else
            continentsCountriesCitiesMap.find(currentContinent)->second.find(currentCountry)->second.push_back(currentCity);
    }

    std::stringstream resultStream{};
    for (auto continentsIter = continentsCountriesCitiesMap.begin(); continentsIter != continentsCountriesCitiesMap.end(); continentsIter++) {
        resultStream << continentsIter->first << ':' << '\n';

        for (auto countriesIter = continentsIter->second.begin(); countriesIter != continentsIter->second.end(); countriesIter++) {
            resultStream << "  " << countriesIter->first << " -> ";

            resultStream << joinAmdOrderStringVector(countriesIter->second) << '\n';
        }
    }

    std::cout << resultStream.str();

    return 0;
}


std::string joinAmdOrderStringVector(std::vector<std::string> &stringVector) {
    std::sort(stringVector.begin(), stringVector.end());

    std::stringstream resultStream{};

    for (int i = 0; i < stringVector.size(); ++i) {
        resultStream << stringVector.at(i);
        if (i < stringVector.size() - 1)
            resultStream << ',';
        resultStream << ' ';
    }

    return resultStream.str();
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
