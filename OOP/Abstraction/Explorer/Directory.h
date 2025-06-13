#pragma once
#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"


class Directory : public FileSystemObject, public FileSystemObjectsContainer {
    std::vector<std::shared_ptr<FileSystemObject> > files;

public:
    Directory(const std::string &name)
        : FileSystemObject(name), files() {}

    size_t getSize() const override {
        size_t totalSize{};

        for (auto iter = this->begin(); iter != this->end(); ++iter)
            totalSize += (*iter)->getSize();

        return totalSize;
    }

    void add(const std::shared_ptr<FileSystemObject> &obj) override {
        this->files.push_back(obj);
    }

    void remove(std::shared_ptr<FileSystemObject> obj) override {
        auto iter = this->files.begin();

        while (iter != this->files.end()) {
            if (*iter == obj)
                break;
            ++iter;
        }

        if (iter != this->files.end())
            this->files.erase(iter);
    }

    std::vector<std::shared_ptr<FileSystemObject> >::const_iterator begin() const {
        return this->files.cbegin();
    }

    std::vector<std::shared_ptr<FileSystemObject> >::const_iterator end() const {
        return this->files.cend();
    }

    ~Directory() override = default;
};