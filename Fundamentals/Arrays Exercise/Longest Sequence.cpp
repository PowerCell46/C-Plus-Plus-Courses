#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;


int main() {
    std::vector<std::pair<int, int>> sequences;

    int arrSize;
    std::cin >> arrSize;

    int *numbers = new int[arrSize];
    // initializing the array of numbers
    for (int i = 0; i < arrSize; ++i)
        std::cin >> numbers[i];

    int currentSequenceNumber = numbers[0], sequenceNumber = 1, biggestSequence = 1;

    for (int i = 1; i < arrSize; ++i) {
        if (numbers[i] == currentSequenceNumber) {
            // if the current number is = to the previous sequence number
            sequenceNumber++;

            if (sequenceNumber > biggestSequence) // keep track of the biggest sequence
                biggestSequence = sequenceNumber;

        } else {
            sequences.push_back({currentSequenceNumber, sequenceNumber}); // save the state of the current sequence

            // reset the values
            currentSequenceNumber = numbers[i];
            sequenceNumber = 1;
        }
    }
    // save the last sequence state
    sequences.push_back({currentSequenceNumber, sequenceNumber});

    for (int i = sequences.size() - 1; i > -1; --i) {
        if (sequences.at(i).second == biggestSequence) {
            // if the current sequence = biggest sequence and it's the last in line
            for (int j = 0; j < biggestSequence; ++j)
                std::cout << sequences.at(i).first << ' ';

            break;
        }
    }

    delete[] numbers;

    return 0;
}
