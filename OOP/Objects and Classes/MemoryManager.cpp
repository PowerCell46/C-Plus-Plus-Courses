#include <iostream>
#include <vector>
#include <string>
#include "Defines.h"
#include <sstream>


ErrorCode executeCommand(const std::string &command, std::vector<int *> &memory) {
    if (std::string(command.begin(), command.begin() + 4) == "Idle")
        return EXECUTE_IDLE;

    std::stringstream currentInputStream{command};
    std::string commandName;
    int index;
    currentInputStream >> commandName >> index;

    if (index >= memory.size() || index < 0)
        return INDEX_OUT_OF_BOUND;

    if (commandName == "Allocate") {
        if (memory[index] != nullptr) {
            return MEMORY_LEAK;
        }

        memory[index] = new int{index};
        return EXECUTE_SUCCESS;
    }

    // Deallocate
    if (memory[index] == nullptr) {
        return DOUBLE_FREE;
    }
    delete memory[index];
    memory[index] = nullptr;
    return EXECUTE_SUCCESS;
}


void printResult(const ErrorCode errorCode, const std::string &command) {
    std::stringstream printResultStr{};
    printResultStr << command << " - ";

    switch (errorCode) { // TODO: USE labels AND goto
        case EXECUTE_SUCCESS:
            printResultStr << "success";
        break;
        case INDEX_OUT_OF_BOUND:
            printResultStr << "out of bound";
        break;
        case EXECUTE_IDLE:
            printResultStr << "this exam is a piece of cake! Where is the OOP already?!?";
        break;
        case MEMORY_LEAK:
            printResultStr << "memory leak prevented, will not make allocation";
        break;
        case DOUBLE_FREE:
            printResultStr << "system crash prevented, will skip this deallocation";
        break;
    }

    std::cout << printResultStr.str() << '\n';
}
