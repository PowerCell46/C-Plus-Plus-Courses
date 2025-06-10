#pragma once


class File : public FileSystemObject {
    std::string content;
public:
    File(const std::string& name, const std::string& content)
        : FileSystemObject(name), content(content) {}

    size_t getSize() const override {
        return this->content.size();
    }

    ~File() override = default;
};