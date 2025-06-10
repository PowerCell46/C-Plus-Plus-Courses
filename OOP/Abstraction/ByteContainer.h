#pragma once


class ByteContainer {
    std::string bytes;

public:
    ByteContainer(const std::string& bytes)
        : bytes(bytes) {}

    std::string getBytes() const {
        return this->bytes;
    }
};