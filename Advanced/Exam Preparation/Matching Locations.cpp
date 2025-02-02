#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#define DOT "."
#define COMMA ','


class MapValue {
public:
    double latitude, longitude;
    std::string line; // Formated input line

    MapValue(const double &latitude, const double &longitude, const std::string &line)
        : latitude(latitude), longitude(longitude), line(line) {
    }
};


int main() {
    std::vector<std::pair<std::string, MapValue> > cityCoordinates; // [<City, MapValue{Lat, Long, Line}>...]

    // Reading the data
    while (true) {
        std::string currentLine;
        std::getline(std::cin, currentLine);

        if (currentLine == DOT)
            break;

        std::stringstream currentLineStream{currentLine};
        std::string currentCity, latitudeStr, longitudeStr;
        double latitude, longitude;

        std::getline(currentLineStream, currentCity, COMMA);
        std::getline(currentLineStream, latitudeStr, COMMA);
        std::getline(currentLineStream, longitudeStr, COMMA);
        latitude = std::stod(latitudeStr);
        longitude = std::stod(longitudeStr);

        cityCoordinates.push_back({currentCity, {latitude, longitude, currentLine}});
    }

    while (true) {
        std::string currentLine;
        std::getline(std::cin, currentLine);

        if (currentLine == DOT)
            break;

        // Searching for an entry with City name == the current line
        auto searchKeyResult = std::find_if(
            cityCoordinates.begin(),
            cityCoordinates.end(),
            [currentLine](const std::pair<std::string, MapValue> &currentPair) {
                return currentPair.first == currentLine;
            });

        if (searchKeyResult == cityCoordinates.end()) { // If there isn't such, search by lat and long
            std::stringstream currentLineStream{currentLine};
            double latitude, longitude;
            currentLineStream >> latitude >> longitude;

            for (const auto &pair: cityCoordinates)
                if (pair.second.latitude == latitude && pair.second.longitude == longitude)
                    std::cout << pair.second.line << '\n';

        } else // If there is such, print the line
            std::cout << (*searchKeyResult).second.line << '\n';
    }

    return 0;
}

/*
Sofia,42.70,23.33
New York,40.6976701,-74.2598732
SoftUni,42.70,23.33
.
Sofia
40.6976701 -74.2598732
42.70 23.33
.
*/
