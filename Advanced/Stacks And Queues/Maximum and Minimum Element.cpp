#include <iostream>
#include <functional>
#include <stack>
#include <sstream>


std::string joinIntStack(std::stack<int>& numbers);

int isBigger(const int& a, const int& b);

int isSmaller(const int& a, const int& b);

int getMinMaxIntStackElement(std::stack<int>& numbersStack, int searchedNumber, const std::function<bool(const int&, const int&)> &compare);


int main() {
    int numberOfCommands;
    std::cin >> numberOfCommands;
    std::cin.ignore();

    std::stack<int> numbersStack;

    std::string currentLine;
    for (int i = 0; i < numberOfCommands; ++i) {
        std::getline(std::cin, currentLine);

        if (currentLine == "2") {
            if (!numbersStack.empty())
                numbersStack.pop();

        } else if (currentLine == "3") {
            if (numbersStack.empty())
                continue;

            std::cout << getMinMaxIntStackElement(numbersStack, -1'000'000, isBigger) << std::endl;

        } else if (currentLine == "4") {
            if (numbersStack.empty())
                continue;

            std::cout << getMinMaxIntStackElement(numbersStack, 1'000'000, isSmaller) << std::endl;

        } else {
            std::stringstream strStream{currentLine};
            int number;
            
            strStream >> number;
            strStream >> number;

            numbersStack.push(number);
        }
    }

    std::cout << joinIntStack(numbersStack) << std::endl;

    return 0;
}

std::string joinIntStack(std::stack<int>& numbers) {
    std::stringstream resultStream{};
    while (!numbers.empty()) {
        resultStream << numbers.top();
        numbers.pop();
        if (numbers.size() != 0)
            resultStream << ',';
        resultStream << ' ';
    }

    return resultStream.str();
}

int isBigger(const int& a, const int& b) {
    return a > b;
}

int isSmaller(const int& a, const int& b) {
    return a < b;
}

int getMinMaxIntStackElement(std::stack<int>& numbersStack, int searchedNumber, const std::function<bool(const int&, const int&)> &compare) {
    std::stack<int> tempStack;
    int currentNumber;

    while (!numbersStack.empty()) {
        currentNumber = numbersStack.top();
        numbersStack.pop();
        tempStack.push(currentNumber);
        
        if (compare(currentNumber, searchedNumber))
            searchedNumber = currentNumber;
    }

    while (!tempStack.empty()) {
        currentNumber = tempStack.top();
        numbersStack.push(currentNumber);
        tempStack.pop();
    }

    return searchedNumber;
}
