#include <iostream>
#include <vector>
#include <sstream>


int main() {
    std::vector<std::string> matchingLocations;

    while (true) {
        std::string currentLine;
        std::getline(std::cin, currentLine);

        if (currentLine == ".")
            break;
        matchingLocations.push_back(currentLine);
    }

    while (true) {
        std::string currentLine;
        std::getline(std::cin, currentLine);

        if (currentLine == ".")
            break;

        if (const auto firstChar = std::tolower(currentLine.at(0)); firstChar >= 'a' && firstChar <= 'z')
            // If the first char is from a-z -> it's a town name
            for (const auto &matchingLocation: matchingLocations) {
                if (matchingLocation.substr(0, currentLine.size()) == currentLine)
                    std::cout << matchingLocation << '\n';
            }

        else {
            // If the first char is ! from a-z -> It's latitude and longitude 
            currentLine.replace(currentLine.find(' '), 1, ","); // replace the space with ','

            for (const auto &matchingLocation: matchingLocations)
                if (
                        currentLine.size() < matchingLocation.size() &&
                        matchingLocation.substr(matchingLocation.size() - currentLine.size()) == currentLine
                    )
                    std::cout << matchingLocation << '\n';
        }
    }
    
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
