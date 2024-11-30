#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using std::string;
using std::vector;
using std::cin;
using std::cout;


std::string calculateAnimalsResult(const std::vector<std::string>& animalVectorData, const std::string& animalType) {
    std::stringstream result{};

    if (animalVectorData.size() == 0) {
        result << "no " << animalType << '!' << std::endl;
        return result.str();
    }

    result << animalVectorData.size() << ' ' << animalType << ": ";

    int sum = 0;
    for (const std::string currentAnimal : animalVectorData) {
        sum += currentAnimal.at(1) - 48;
        result << currentAnimal << ' ';
    }

    result << std::fixed << std::setprecision(2);
    result << "with avg. size " << (sum > 0 ? sum / (animalVectorData.size() + 0.0) : 0) << std::endl;

    return result.str();
}


int main() {
    std::string input, currentInput;
    std::getline(std::cin, input);
    std::stringstream inputStringStream{input};

    std::vector<std::string> cows;
    std::vector<std::string> sheep;
    std::vector<std::string> others;

    while (inputStringStream >> currentInput) {
        switch (currentInput.at(0)) {
            case 'C':
                cows.push_back(currentInput);
                break;

            case 'S':
                sheep.push_back(currentInput);
                break;

            default:
                others.push_back(currentInput);
                break;
        }
    }

    std::cout << calculateAnimalsResult(cows, "cows");
    std::cout << calculateAnimalsResult(sheep, "sheep");
    std::cout << calculateAnimalsResult(others, "others");

    return 0;
}
