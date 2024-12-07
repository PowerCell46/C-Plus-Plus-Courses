#include <iostream>
#include <queue>
#include <sstream>


int main() {
    int numberOfGasStations;
    std::cin >> numberOfGasStations;

    std::queue<std::pair<int, int>> dataQueue;


    // seeding the data to the queue
    for (int i = 0; i < numberOfGasStations; ++i) {
        int givenPetrol, distanceToNextStation;
        std::cin >> givenPetrol >> distanceToNextStation;

        dataQueue.push({givenPetrol, distanceToNextStation});
    }


    int index = 0;
    while (!dataQueue.empty()) {
        int collectedFuel = dataQueue.front().first;
        int distance = dataQueue.front().second;

        if (collectedFuel >= distance) { // case where you are able to reach the next gas station
            collectedFuel -= distance; // decreasing the fuel with the distance

            std::queue<std::pair<int, int>> tempQueue; // initializing a queue to store the data and the order
            tempQueue.push(dataQueue.front());
            dataQueue.pop();

            while (!dataQueue.empty()) {
                collectedFuel += dataQueue.front().first;
                distance = dataQueue.front().second;

                if (collectedFuel >= distance) {
                    collectedFuel -= distance;
                    tempQueue.push(dataQueue.front());
                    dataQueue.pop();

                } else // somewhere ahead the collected fuel isn't enough -> need to revert back
                    break;
            }

            if (dataQueue.empty()) { // case where the current position is valid
                std::cout << index << std::endl;
                return 0;

            } else { // case where you have to revert and continue with the next index (revert the dataQueue state)
                std::queue<std::pair<int, int>> newTempQueue;
                
                while (!dataQueue.empty()) {
                    newTempQueue.push(dataQueue.front());
                    dataQueue.pop();
                }

                while (!tempQueue.empty()) {
                    newTempQueue.push(tempQueue.front());
                    tempQueue.pop();
                    index++;
                }

                while (!newTempQueue.empty()) {
                    dataQueue.push(newTempQueue.front());
                    newTempQueue.pop();
                }
            }

        } else { // case where you aren't able to reach the next gas station
            index++;
            std::queue<std::pair<int, int>> tempQueue;
            std::pair<int, int> first = dataQueue.front();
            dataQueue.pop();
            
            while (!dataQueue.empty()) {
                tempQueue.push(dataQueue.front());
                dataQueue.pop();
            }

            while (!tempQueue.empty()) {
                dataQueue.push(tempQueue.front());
                tempQueue.pop();
            }
            
            dataQueue.push(first);

        }
    }

    return 0;
}
