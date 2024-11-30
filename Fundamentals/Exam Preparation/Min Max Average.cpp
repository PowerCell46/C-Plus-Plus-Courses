#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using std::string;
using std::vector;
using std::cin;
using std::cout;


int findMaxNumber(const std::vector<int>& numbersVector) {
    int maxElement = numbersVector.at(0);

    for (int i = 1; i < numbersVector.size(); ++i) {
        if (numbersVector.at(i) > maxElement)
            maxElement = numbersVector.at(i);
    }

    return maxElement;
}

int findMinNumber(const std::vector<int>& numbersVector) {
    int minElement = numbersVector.at(0);

    for (int i = 1; i < numbersVector.size(); ++i) {
        if (numbersVector.at(i) < minElement)
            minElement = numbersVector.at(i);
    }

    return minElement;
}

double findAverage(const std::vector<int>& evenVector, const std::vector<int>& oddVector) {
    int sum = 0;

    for (const int num : evenVector)
        sum += num;
    for (const int num : oddVector)
        sum += num;

    return (double) sum / (evenVector.size() + oddVector.size());
}


int main() {
    int numberOfNumbers;
    std::cin >> numberOfNumbers;
    std::vector<int> evenPositionNumbers;
    std::vector<int> oddPositionNumbers;
    std::vector<int> allNumbers;

    evenPositionNumbers.reserve(numberOfNumbers / 2 + 1);
    oddPositionNumbers.reserve(numberOfNumbers / 2 + 1);
    allNumbers.reserve(numberOfNumbers);

    for (int i = 0; i < numberOfNumbers; ++i) {
        int currentNumber;
        std::cin >> currentNumber;

        allNumbers.push_back(currentNumber);
        if (i % 2 == 0)
            evenPositionNumbers.push_back(currentNumber);
        else
            oddPositionNumbers.push_back(currentNumber);
    }

    std::stringstream result{};

    result << std::fixed << std::setprecision(2);
    result << findMaxNumber(oddPositionNumbers) << ".00 ";
    result << findMinNumber(evenPositionNumbers) << ".00 ";
    result << findAverage(evenPositionNumbers, oddPositionNumbers) << '\n';

    for (auto iter = allNumbers.end() -1; iter >= allNumbers.begin(); iter--)
        result << *iter << ' ';

    std::cout << result.str() << std::endl;

    return 0;
}

