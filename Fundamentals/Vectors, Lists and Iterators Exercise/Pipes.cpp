#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;


int main() {
    int arrSize;
    std::cin >> arrSize;

    int* thisYearsValues = new int[arrSize];
    int* lastYearsValues = new int[arrSize];


    for (int i = 0; i < arrSize; ++i)
        std::cin >> thisYearsValues[i];

    for (int i = 0; i < arrSize; ++i)
        std::cin >> lastYearsValues[i];


    for (int i = 0; i < arrSize; ++i) {
        const int corrosionPerYear = lastYearsValues[i] - thisYearsValues[i];

        int yearsCounter = 1;

        while (thisYearsValues[i] >= corrosionPerYear) {
            thisYearsValues[i] -= corrosionPerYear;
            yearsCounter++;
        }

        std::cout << yearsCounter << ' ';
    }


    delete[] thisYearsValues;
    delete[] lastYearsValues;

    return 0;
}
