#pragma once
#include <memory>
#include "CalculationEngine.h"
#include "FinalInputInterpreter.h"


std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine &engine) {
    auto pointer = std::make_shared<FinalInputInterpreter>(FinalInputInterpreter{engine});

    return pointer;
};
