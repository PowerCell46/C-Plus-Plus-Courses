#include <iostream>

int main() {
    int numArrays;
    std::cin >> numArrays;

    std::pair<int, std::string> biggestSumPair{INT_MIN, ""};


    for (int i = 0; i < numArrays; i++) {
        int currentSize, currentSum = 0;
        std::cin >> currentSize;

        int *arr = new int[currentSize];

        for (int j = 0; j < currentSize; ++j) {
            std::cin >> arr[j]; // adding the value to the array
            currentSum += arr[j]; // adding the value to the currentSum
        }

        if (currentSum > biggestSumPair.first) { // case where the currentSum is bigger than the previous ones
            biggestSumPair.first = currentSum; // setting the key

            std::string currentLine;
            for (int index = 0; index < currentSize; index++)
                currentLine += std::to_string(arr[index]) + " ";
            biggestSumPair.second = currentLine; // setting the value
        }

        delete[] arr; // deleting the array from the dynamic memory
    }

    std::cout << "Biggest Sum: " << biggestSumPair.first << '\n' << biggestSumPair.second << std::endl;
    
    return 0;
}
