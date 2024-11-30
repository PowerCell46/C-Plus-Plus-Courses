#include <iostream>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::cin;
using std::cout;


int main() {
    std::vector<std::string> firstVector;
    std::vector<std::string> secondVector;

    firstVector.reserve(10);
    secondVector.reserve(10);

    std::string firstLine, secondLine, currentElement;
    std::getline(std::cin, firstLine);
    std::getline(std::cin, secondLine);

    std::stringstream firstStream{firstLine};
    std::stringstream secondStream{secondLine};

    while (firstStream >> currentElement)
        firstVector.push_back(currentElement);

    while (secondStream >> currentElement)
        secondVector.push_back(currentElement);

    for (int i = 0; i < (std::max(firstVector.size(), secondVector.size())); ++i) {
        if (i >= firstVector.size())
            std::cout << '-';

        else if (i >= secondVector.size())
            std::cout << '+';

        else if (firstVector.at(i).size() > secondVector.at(i).size())
            std::cout << '<';

        else if (firstVector.at(i).size() < secondVector.at(i).size())
            std::cout << '>';

        else {
            const std::string firstVectorElement = firstVector.at(i);
            const std::string secondVectorElement = secondVector.at(i);

            if (firstVectorElement == secondVectorElement)
                std::cout << '=';

            else {
                for (int j = 0; j < firstVectorElement.size(); ++j) {
                    if (firstVectorElement.at(j) > secondVectorElement.at(j)) {
                        std::cout << '<';
                        break;
                    }

                    if (firstVectorElement.at(j) < secondVectorElement.at(j)) {
                        std::cout << '>';
                        break;
                    }
                }
            }
        }
    }

    return 0;
}

/*
123456789012345678901234567890 98765432109876543210987654          123456789098765432101234567890
234567890123456789012345678901 876543210987654321098765432109 23456780987654321012345678901
*/
