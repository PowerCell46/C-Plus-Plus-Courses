#pragma once
#include <sstream>

class DigitsExtractor : public Extractor {

public:
    DigitsExtractor(std::istream& stream) :
        Extractor(stream) {}

    bool process(char symbol, std::string &output) override {
        if (symbol >= '0' && symbol <= '9') { // Filter only the digits
            output += symbol;
            return true;
        }
        return false;
    }

    ~DigitsExtractor() override = default;
};

class NumbersExtractor : public Extractor {

public:
    NumbersExtractor(std::istream& stream) :
        Extractor(stream) {}

    bool process(char symbol, std::string &output) override {
        static std::string numberStr; // Buffer containing the whole number as a string

        if (symbol >= '0' && symbol <= '9') {
            numberStr += symbol;
            return false;
        }

        if (!numberStr.empty()) {
            output = numberStr;
            numberStr = "";
            return true;
        }

        return false;
    }

    ~NumbersExtractor() override = default;
};

class QuotesExtractor : public Extractor {

public:
    QuotesExtractor(std::istream& stream) :
        Extractor(stream) {}

    bool process(char symbol, std::string &output) override {
        static std::string quoteStr; // Buffer containing the whole quote as a string
        constexpr char DEFAULT_START_QUOTE_SYMBOL = '~';

        if (symbol == '"') { // If a quote starts or ends
            if (!quoteStr.empty()) { // The quote is ending
                output = quoteStr;
                quoteStr = "";
                return true;
            }

            quoteStr += DEFAULT_START_QUOTE_SYMBOL;

        } else {
            if (!quoteStr.empty()) { // Inserting in the quote
                if (quoteStr.at(0) == DEFAULT_START_QUOTE_SYMBOL) // Removing/Replacing the useless character
                    quoteStr.at(0) = symbol;
                else
                    quoteStr += symbol;
            }
        }

        return false;
    }

    ~QuotesExtractor() override = default;
};


std::shared_ptr<Extractor> getExtractor(const std::string& extractType, std::istringstream& lineIn) {
    if (extractType == "digits") {
        auto pointer = std::make_shared<DigitsExtractor>(DigitsExtractor{lineIn});
        return pointer;
    }

    if (extractType == "numbers") {
        auto pointer = std::make_shared<NumbersExtractor>(NumbersExtractor{lineIn});
        return pointer;
    }

    auto pointer = std::make_shared<QuotesExtractor>(QuotesExtractor{lineIn});
    return pointer;
}
