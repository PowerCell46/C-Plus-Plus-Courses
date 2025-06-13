#pragma once
#include "FileSystemObject.h"
#include "Directory.h"
#include "File.h"
#include <iostream>
#include <set>


class Explorer {
    std::vector<std::shared_ptr<FileSystemObject> >& rootObjects;
    std::string currentPath;
    std::set<std::pair<std::string, std::string>> clipboard;
    std::shared_ptr<Shortcuts> shortcuts;

    static std::shared_ptr<FileSystemObjectsContainer> navigateToParentDirectory(std::string remainingPathToFolder, std::vector<std::shared_ptr<FileSystemObject> > &currentDirectoryObjects) {
        if (remainingPathToFolder.empty()) // current folder
            return nullptr;

        while (true) {
            std::string currentSearchedDirectoryName{};

            for (auto iter = remainingPathToFolder.begin(); iter != remainingPathToFolder.end(); ++iter) // Substring the current searched folder name as a var and remove it from the remainingPathToFolder
                if (*iter == '\\') {
                    currentSearchedDirectoryName = std::string(remainingPathToFolder.begin(), iter);
                    remainingPathToFolder = std::string(iter + 1, remainingPathToFolder.end());

                    break;
                }

            for (const std::shared_ptr<FileSystemObject>& fileSystemObject : currentDirectoryObjects) // Iterate through the obj in the current directory
                if (fileSystemObject->getName() == currentSearchedDirectoryName) {
                    if (const std::shared_ptr<FileSystemObjectsContainer> directory = std::dynamic_pointer_cast<FileSystemObjectsContainer>(fileSystemObject)) {
                        currentDirectoryObjects = std::vector<std::shared_ptr<FileSystemObject>>(directory->begin(), directory->end());

                        if (remainingPathToFolder.empty())
                            return directory;
                        else
                            break;
                    }
                }
        }
    }

public:
    Explorer(std::vector<std::shared_ptr<FileSystemObject> >& rootObjects)
        : rootObjects(rootObjects), currentPath(), clipboard(), shortcuts(nullptr) {}

    void createFile(const std::string& fileName, const std::string& content) {
        std::vector<std::shared_ptr<FileSystemObject>> currentDirectory = this->rootObjects;
        std::shared_ptr<FileSystemObjectsContainer> directory = navigateToParentDirectory(this->currentPath, currentDirectory);

        if (directory == nullptr)
            this->rootObjects.push_back(std::make_shared<File>(File{fileName, content}));
        else
            directory->add(std::make_shared<File>(File{fileName, content}));
    }

    void createDirectory(const std::string& directoryName) {
        std::vector<std::shared_ptr<FileSystemObject>> currentDirectory = this->rootObjects;
        std::shared_ptr<FileSystemObjectsContainer> directory = navigateToParentDirectory(this->currentPath, currentDirectory);

        if (directory == nullptr)
            this->rootObjects.push_back(std::make_shared<Directory>(Directory{directoryName}));
        else
            directory->add(std::make_shared<Directory>(Directory{directoryName}));
    }

    void cut(const std::string& path) {
        this->clipboard.insert({this->currentPath, path});
    }

    void paste() {
        std::vector<std::shared_ptr<FileSystemObject> > cutObjects;

        for (const std::pair<std::string, std::string>& currentCutPair : this->clipboard) {
            std::vector<std::shared_ptr<FileSystemObject>> currentDirectory = this->rootObjects;
            std::shared_ptr<FileSystemObjectsContainer> directory = navigateToParentDirectory(currentCutPair.first, currentDirectory);

            if (directory == nullptr) {
                for (auto iter = this->rootObjects.begin(); iter != this->rootObjects.end(); ++iter) {
                    if ((*iter)->getName() == currentCutPair.second) {
                        cutObjects.push_back((*iter));
                        this->rootObjects.erase(iter);
                        break;
                    }
                }

            } else {
                for (auto iter = directory->begin(); iter != directory->end(); ++iter) {
                    if ((*iter)->getName() == currentCutPair.second) {
                        cutObjects.push_back(*iter);
                        directory->remove(*iter);
                        break;
                    }
                }
            }
        }

        std::vector<std::shared_ptr<FileSystemObject>> currentDirectory = this->rootObjects;
        std::shared_ptr<FileSystemObjectsContainer> directory = navigateToParentDirectory(this->currentPath, currentDirectory);

        if (directory == nullptr) {
            for (const std::shared_ptr<FileSystemObject>& cutObject : cutObjects)
                this->rootObjects.push_back(cutObject);

        } else {
            for (const std::shared_ptr<FileSystemObject>& cutObject : cutObjects)
                directory->add(cutObject);
        }

        this->clipboard.clear();
    }

    void createShortcut(const std::string& name) {
        std::vector<std::shared_ptr<FileSystemObject>> currentDirectory = this->rootObjects;
        std::shared_ptr<FileSystemObjectsContainer> directory = navigateToParentDirectory(this->currentPath, currentDirectory);

        if (directory == nullptr) {
            for (auto iter = this->rootObjects.begin(); iter != this->rootObjects.end(); ++iter)
                if ((*iter)->getName() == name) {
                    if (this->shortcuts == nullptr) {
                        this->shortcuts = std::make_shared<Shortcuts>();
                        this->shortcuts->add(*iter); // Add the found object before push_back, since push_back may invalidate the iterator
                        this->rootObjects.push_back(this->shortcuts);

                    } else
                        this->shortcuts->add(*iter);

                    break;
                }

        } else {
            for (auto iter = directory->begin(); iter != directory->end(); ++iter)
                if ((*iter)->getName() == name) {
                    if (this->shortcuts == nullptr) {
                        this->shortcuts = std::make_shared<Shortcuts>();
                        this->rootObjects.push_back(this->shortcuts);
                    }
                    this->shortcuts->add(*iter);

                    break;
                }
        }
    }

    void navigate(const std::string& path) {
        if (path == "..") { // Go to the parent's directory
            for (auto riter = this->currentPath.rbegin() + 1; riter != this->currentPath.rend(); ++riter)
                if (*riter == '\\') {
                    this->currentPath = std::string(this->currentPath.begin(), riter.base());
                    return;
                }

            this->currentPath.clear();

        } else // Go in a nested directory
            this->currentPath += path + std::string("\\");
    }
};
