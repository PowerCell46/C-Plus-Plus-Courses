#pragma once
#include "Filter.h"

class FilterFactory : public Filter {
    static bool filterCapitalLetters(const char& ch) {
        return ch >= 'A' && ch <= 'Z';
    }
    static bool filterNonCapitalLetters(const char& ch) {
        return ch >= 'a' && ch <= 'z';
    }
    static bool filterDigits(const char& ch) {
        return ch >= '0' && ch <= '9';
    }

    bool shouldFilterOut(char symbol) const override {
        if (this->filterType == "A-Z")
            return filterCapitalLetters(symbol);
        if (this->filterType == "a-z")
            return filterNonCapitalLetters(symbol);
        if (this->filterType == "0-9")
            return filterDigits(symbol);

    }
    std::string filterType;
public:
    FilterFactory() = default;

    FilterFactory(const std::string& filterType) :
        filterType(filterType) {}

    static Filter* buildFilter(const std::string& filterType) {
        return new FilterFactory{filterType};
    }
};
