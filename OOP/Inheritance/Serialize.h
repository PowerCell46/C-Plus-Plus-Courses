#pragma once

#include "Company.h"
#include <sstream>
#include <iostream>

byte* serializeToMemory(const std::string& line, size_t& bytesWritten) {
    std::stringstream lineStream{line};
    Company company;

    std::vector<std::pair<size_t, byte*>> dataVector;
    bytesWritten = 1; // Size for the number of companies

    while (lineStream >> company) {
        constexpr size_t idSize = 1; // Size for the company id
        const size_t nameSize = company.getName().size() + 1; // Size for the name + \0 at the end
        constexpr size_t numberOfEmployeesSize = 1; // Size for the num of employees
        const size_t employeesSize = company.getEmployees().size() * 2; // Size for each employee's 2 initials

        const size_t currentTotalSize = idSize + nameSize + numberOfEmployeesSize + employeesSize; // Total needed size

        size_t currentIndex = 0;
        byte* currentByteArray = new byte[currentTotalSize]{}; // Init the current byte array
        
        *(currentByteArray + currentIndex) = company.getId(); // Insert the id
        ++currentIndex;

        for (const char& ch : company.getName()) { // Insert the name
            *(currentByteArray + currentIndex) = ch;
            ++currentIndex;
        }
        *(currentByteArray + currentIndex) = '\0'; // Add the \0
        ++currentIndex;

        *(currentByteArray + currentIndex) = company.getEmployees().size(); // Add the num of employees
        ++currentIndex;

        for (const std::pair<char, char>& employeePair : company.getEmployees()) { // Add the employees
            *(currentByteArray + currentIndex) = employeePair.first; // Add the first initial
            ++currentIndex;
            
            *(currentByteArray + currentIndex) = employeePair.second; // Add the second initial
            ++currentIndex;
        }

        dataVector.push_back({currentTotalSize, currentByteArray});
        bytesWritten += currentTotalSize;
    }

    byte* byteArray = new byte[bytesWritten]{}; // Create a byte array with the final size
    size_t index = 0;
    
    *(byteArray + index) = dataVector.size(); // Add the number of companies
    ++index;

    for (const std::pair<size_t, byte *>& currentDataPair : dataVector) { // Copy all the data to the final array
        std::copy(currentDataPair.second, currentDataPair.second + currentDataPair.first, byteArray + index);
        index += currentDataPair.first;
    }

    return byteArray;
}
