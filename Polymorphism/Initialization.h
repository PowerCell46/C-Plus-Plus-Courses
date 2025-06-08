#pragma once
#include <memory>
#include "CommandInterface.h"
#include "FinalCommandInterface.h"

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text) {
    auto pointer = std::make_shared<FinalCommandInterface>(FinalCommandInterface{text});
    pointer->init();

    return pointer;
}
