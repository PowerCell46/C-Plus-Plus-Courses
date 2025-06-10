#pragma once
#include "ByteContainer.h"


class File : public FileSystemObject, public ByteContainer {
public:
    File(const std::string& name, const std::string& bytes)
        : FileSystemObject(name), ByteContainer(bytes) {}

    size_t getSize() const override {
        return this->getBytes().size();
    }
};
