#pragma once
#include "CommandInterface.h"
#include "TextTransform.h"


class FinalCommandInterface : public CommandInterface {
private:
    static std::string savedBuffer;

    class CutTransform : public TextTransform {
    public:
        virtual void invokeOn(std::string &text, int startIndex, int endIndex) override {
            if (startIndex == endIndex) {
                savedBuffer = "";
                return;
            }

            std::stringstream cutBufferStream{};
            std::stringstream newStringStream{};

            for (int i = 0; i < text.size(); ++i) {
                if (i >= startIndex && i < endIndex)
                    cutBufferStream << text.at(i);
                else
                    newStringStream << text.at(i);
            }

            savedBuffer = cutBufferStream.str();
            text = newStringStream.str();
        }
    };

    class PasteTransform : public TextTransform {
    public:
        virtual void invokeOn(std::string &text, int startIndex, int endIndex) override {
            std::stringstream beforeStream{};
            std::stringstream afterStream{};

            if (startIndex == endIndex) {
                for (int i = 0; i < text.size(); ++i) {
                    if (i < startIndex)
                        beforeStream << text.at(i);
                    else
                        afterStream << text.at(i);
                }

            } else {
                for (int i = 0; i < text.size(); ++i) {
                    if (i < startIndex)
                        beforeStream << text.at(i);
                    else if (i >= endIndex)
                        afterStream << text.at(i);
                }
            }

            text = beforeStream.str() + savedBuffer + afterStream.str();
        }
    };

    std::vector<Command> initCommands() override {
        std::vector<Command> commands = CommandInterface::initCommands();

        commands.push_back(Command("cut", std::make_shared<CutTransform>()));
        commands.push_back(Command("paste", std::make_shared<PasteTransform>()));

        return commands;
    }
public:
    FinalCommandInterface(std::string &text) : CommandInterface(text) {
        savedBuffer = "";
    }
};

std::string FinalCommandInterface::savedBuffer;
