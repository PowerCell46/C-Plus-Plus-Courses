#include <iostream>
#include <sstream>


int main() {
    int arrSize;
    std::cin >> arrSize;

    int* numbers = new int[arrSize];
    for (int i = 0; i < arrSize; ++i)
        std::cin >> numbers[i];

    int iterations = 1;

    while (iterations < arrSize) {
        for (int i = 0; i < (arrSize - iterations); ++i)
            numbers[i] += numbers[i + 1];
        iterations++;
    }

    std::cout << numbers[0] << std::endl;

    delete[] numbers;

    return 0;
}
