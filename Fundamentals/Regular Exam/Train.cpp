#include <iostream>
#include <vector>
#include <sstream>


#define END "end"
#define PRINT_COMMAND "P"
#define MOVE_COMMAND 'M'
#define LEAVE_COMMAND 'L'
#define END_COMMAND "E"
#define EMPTY_WAGON "empty"
#define WAGON_PRINT_SEPARATOR '|'


std::string printTrainWagons(const std::vector<std::string> &train);

void moveWagons(std::vector<std::string> &train, int &oldPosition, int &newPosition);


int main() {
    std::vector<std::string> train;

    while (true) {
        std::string currentWagon;
        std::getline(std::cin, currentWagon);

        if (currentWagon == END)
            break;

        train.push_back(currentWagon);
    }

    while (true) {
        std::string currentCommand;
        std::getline(std::cin, currentCommand);

        if (currentCommand == PRINT_COMMAND)
            std::cout << printTrainWagons(train) << std::endl;

        if (currentCommand.at(0) == MOVE_COMMAND) {
            std::stringstream lineStream{currentCommand};
            std::string command;
            int oldPosition, newPosition;

            lineStream >> command >> oldPosition >> newPosition;

            moveWagons(train, oldPosition, newPosition);
            std::cout << printTrainWagons(train) << std::endl;
        }

        if (currentCommand.at(0) == LEAVE_COMMAND) {
            std::stringstream lineStream{currentCommand};
            std::string command;
            int removeWagonPosition;

            lineStream >> command >> removeWagonPosition;

            train.erase(train.begin() + removeWagonPosition - 1);
            std::cout << printTrainWagons(train) << std::endl;
        }

        if (currentCommand == END_COMMAND)
            break;
    }

    return 0;
}


std::string printTrainWagons(const std::vector<std::string> &train) {
    std::stringstream resultStream{};

    for (const std::string &wagon: train) {
        resultStream << WAGON_PRINT_SEPARATOR << (wagon != EMPTY_WAGON ? wagon : " ");
    }
    resultStream << WAGON_PRINT_SEPARATOR;

    return resultStream.str();
}


void moveWagons(std::vector<std::string> &train, int &oldPosition, int &newPosition) {
    oldPosition--;
    newPosition--;

    while (oldPosition > newPosition) {
        const std::string temp = train.at(oldPosition);

        train.at(oldPosition) = train.at(oldPosition - 1);
        train.at(oldPosition - 1) = temp;

        oldPosition--;
    }

    while (newPosition > oldPosition) {
        const std::string temp = train.at(oldPosition);

        train.at(oldPosition) = train.at(oldPosition + 1);
        train.at(oldPosition + 1) = temp;

        oldPosition++;
    }
}
