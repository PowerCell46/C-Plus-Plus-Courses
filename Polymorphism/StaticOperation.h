#pragma once
#include "Operation.h"


class StaticOperation : public Operation {
    int result;
    bool bl = true;

    bool isCompleted() override {
        this->bl = !this->bl;
        return this->bl;
    }

    void addOperand(int operand) override {
        this->result = operand;
    }

    int getResult() override {
        return this->result;
    }
};
