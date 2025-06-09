#pragma once

#include <memory>
#include <stack>
#include <string>
#include "Operation.h"
#include "CalculationEngine.h"
#include "DivisionOperation.h"
#include "InputInterpreter.h"
#include "MultiplicationOperation.h"
#include "StaticOperation.h"


class FinalInputInterpreter : public InputInterpreter {
public:
    static int memory;
    CalculationEngine &sameEngine;
    std::stack<int> saveBuffer;

    FinalInputInterpreter(CalculationEngine &engine)
        : InputInterpreter(engine), sameEngine(engine), saveBuffer() {}

    bool interpret(std::string input) {
        std::istringstream numberParseStream(input);

        int number;
        if (numberParseStream >> number) {
            sameEngine.pushNumber(number);

        } /* else if (input == "ms") { // WOULD BE TIMES EASIER IF THIS METHOD WAS VIRTUAL IN THE BASE CLASS!
            this->saveBuffer.push(sameEngine.getCurrentResult());

        } else if (input == "mr") {
            const int lastSave = this->saveBuffer.top();
            this->saveBuffer.pop();
            this->interpret(std::to_string(lastSave));

        } */
        else {
            sameEngine.pushOperation(this->getOperation(input));
        }

        return true;
    }

    std::shared_ptr<Operation> getOperation(std::string operation) override {
        if (operation == "*") {
            return std::make_shared<MultiplicationOperation>();

        } else if (operation == "/") {
            return std::make_shared<DivisionOperation>();

        } else if (operation == "ms") {
            this->saveBuffer.push(sameEngine.getCurrentResult());

        } else if (operation == "mr") {
            const int lastSave = this->saveBuffer.top();
            this->saveBuffer.pop();
            this->interpret(std::to_string(lastSave));
        }

        return std::make_shared<StaticOperation>();
    }
};
