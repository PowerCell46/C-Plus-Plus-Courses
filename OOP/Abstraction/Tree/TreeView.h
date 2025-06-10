#pragma once
#include "FileSystemObject.h"
#include <vector>
#include <sstream>


void printDirectory(const std::shared_ptr<FileSystemObjectsContainer>& directory, const int& ident, std::stringstream& resultStream);


std::string repeatString(const std::string& str, int n);


std::string getTreeView(const std::vector<std::shared_ptr<FileSystemObject>>& rootObjects) {
    std::stringstream resultStream{};

    for (const std::shared_ptr<FileSystemObject>& fileSystemObject : rootObjects) {
        resultStream << fileSystemObject->getName() << '\n';
        int currentIdent = 1;

        if (const std::shared_ptr<FileSystemObjectsContainer> directory = std::dynamic_pointer_cast<FileSystemObjectsContainer>(fileSystemObject))
            printDirectory(directory, currentIdent, resultStream);
    }

    return resultStream.str();
}

void printDirectory(const std::shared_ptr<FileSystemObjectsContainer>& directory, const int& ident, std::stringstream& resultStream) {
    std::map<std::string, std::shared_ptr<FileSystemObject>> fileObjectsMap;

    // Needed so they are sorted by their name
    for (auto iter = directory->begin(); iter != directory->end(); ++iter)
        fileObjectsMap.insert({(*iter)->getName(), (*iter)});

    for (const std::pair<const std::string, std::shared_ptr<FileSystemObject>>& objectsMap : fileObjectsMap) {
        resultStream << repeatString("--->", ident) << objectsMap.first << '\n';

        if (const std::shared_ptr<FileSystemObjectsContainer> dir = std::dynamic_pointer_cast<FileSystemObjectsContainer>(objectsMap.second))
            printDirectory(dir, ident + 1, resultStream);
    }
}

std::string repeatString(const std::string& str, int n) {
    std::string result;
    for (int i = 0; i < n; ++i)
        result += str;
    return result;
}
