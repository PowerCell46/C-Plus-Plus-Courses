#include <iostream>
#include <vector>
#include <sstream>

#define DOT_STR "."

// Singleton Class with private methods for the mainLogic()
class MatchingLocations {
    MatchingLocations() = default;

    ~MatchingLocations() = default;

    std::vector<std::string> initMatchingLocations() {
        std::vector<std::string> matchingLocations;

        while (true) {
            std::string currentLine;
            std::getline(std::cin, currentLine);

            if (currentLine == DOT_STR)
                break;
            matchingLocations.push_back(currentLine);
        }

        return matchingLocations;
    }

    void searchByCityName(const std::vector<std::string> &matchingLocations, const std::string &cityName) {
        for (const auto &matchingLocation: matchingLocations)
            if (matchingLocation.substr(0, cityName.size()) == cityName)
                std::cout << matchingLocation << '\n';
    }

    void searchByCoordinates(const std::vector<std::string> &matchingLocations, std::string &coordinates) {
        coordinates.replace(coordinates.find(' '), 1, ",");

        for (const auto &matchingLocation: matchingLocations)
            if (
                coordinates.size() < matchingLocation.size() &&
                matchingLocation.substr(matchingLocation.size() - coordinates.size()) == coordinates
            )
                std::cout << matchingLocation << '\n';
    }

public:
    void mainLogic() {
        std::vector<std::string> matchingLocations = initMatchingLocations();

        while (true) {
            std::string currentLine;
            std::getline(std::cin, currentLine);

            if (currentLine == DOT_STR)
                break;

            if (const auto firstChar = std::tolower(currentLine.at(0)); firstChar >= 'a' && firstChar <= 'z')
                searchByCityName(matchingLocations, currentLine);
            else {
                searchByCoordinates(matchingLocations, currentLine);
            }
        }
    }

    MatchingLocations(const MatchingLocations &) = delete;

    MatchingLocations &operator=(const MatchingLocations &) = delete;

    static MatchingLocations &getInstance() {
        static MatchingLocations instance;
        return instance;
    }
};

int main() {
    MatchingLocations& matchingLocations = MatchingLocations::getInstance();

    matchingLocations.mainLogic();
    
    return 0;
}

// Sofia,42.70,23.33
// New York,40.6976701,-74.2598732
// SoftUni,42.70,23.33
// .
// Sofia
// 40.6976701 -74.2598732
// 42.70 23.33
// .
