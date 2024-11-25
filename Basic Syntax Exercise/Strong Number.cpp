#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;


int main() {
    int totalSumFactorial = 0;
    std::string numberStr;
    std::cin >> numberStr;

    for (const char ch : numberStr) {
        int currentNumber = (int) ch - 48, currentFactorialSum = 1; // parsing the current char to int

        for (int i = 1; i <= currentNumber; ++i) // calculating the factorial for the current int
            currentFactorialSum *= i;

        totalSumFactorial += currentFactorialSum; // adding current factorial -> total factorial
    }

    std::cout << (totalSumFactorial == std::stoi(numberStr) ? "yes" : "no") << std::endl;

    return 0;
}
