#include <iostream>
#include <vector>
#include <list>
#include <sstream>

using std::string;
using std::vector;
using std::cin;
using std::cout;


struct TwoLastNums {
    int lastNum;
    int secondToLastNum;
};


TwoLastNums removeAndReturnLastTwoListNumbers(std::list<int> &numbers) {
    int last = 0, secondToLast = 0;

    last = *numbers.rbegin(); // last one
    secondToLast = *(++numbers.rbegin()); // second to last

    numbers.pop_back();
    numbers.pop_back();

    return {last, secondToLast};
}


int main() {
    std::list<int> numbers;
    std::string currentInput;

    while (true) {
        std::cin >> currentInput;

        if (currentInput == "end")
            break;

        if (currentInput == "sum") {
            const TwoLastNums twoNums = removeAndReturnLastTwoListNumbers(numbers);
            numbers.push_back((twoNums.lastNum + twoNums.secondToLastNum));

        } else if (currentInput == "subtract") {
            const TwoLastNums twoNums = removeAndReturnLastTwoListNumbers(numbers);
            numbers.push_back((twoNums.lastNum - twoNums.secondToLastNum));

        } else if (currentInput == "concat") {
            const TwoLastNums twoNums = removeAndReturnLastTwoListNumbers(numbers);
            numbers.push_back(std::stoi(std::to_string(twoNums.secondToLastNum) + std::to_string(twoNums.lastNum)));

        } else if (currentInput == "discard")
            numbers.pop_back();

        else
            numbers.push_back(std::stoi(currentInput));
    }

    std::stringstream strStream{};
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
        strStream << *iter << '\n';

    std::cout << strStream.str() << std::endl;

    return 0;
}
