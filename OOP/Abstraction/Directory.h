#pragma once


class Directory : public FileSystemObject, public FileSystemObjectsContainer {
    std::vector<std::shared_ptr<FileSystemObject>> files;
public:
    Directory(const std::string& name)
        : FileSystemObject(name), files() {}

    void add(const std::shared_ptr<FileSystemObject> &obj) override {
        this->files.push_back(obj);
    }

    ~Directory() override = default; // TODO: ???

    size_t getSize() const override {
        size_t sumOfSizes{};
        for (const std::shared_ptr<FileSystemObject>& fileSystemObject : this->files)
            sumOfSizes += fileSystemObject->getSize();

        return sumOfSizes;
    };
};

