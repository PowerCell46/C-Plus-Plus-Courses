#ifndef PROFITREPORT_H
#define PROFITREPORT_H
#include "Company.h"
#include <map>

std::string join(const std::vector<std::string>& vec) {
    std::stringstream resultStream{};

    auto iter = vec.cbegin();
    iterForLoop:
    if (iter != vec.cend() - 1) {
        resultStream << *iter << '\n';
        ++iter;
        goto iterForLoop;
    }

    resultStream << *vec.rbegin();

    return resultStream.str();
}

std::string getProfitReport(Company* begin, const Company* end, const std::map<int, ProfitCalculator>& profitCalculatorsByCompany) {
    std::vector<std::string> resultVector;

    whileLoopBegin:
        const int profit = profitCalculatorsByCompany.at(begin->getId()).calculateProfit(*begin);
        resultVector.push_back(begin->getName() + std::string(" = ") + std::to_string(profit));
        ++begin;
        if (begin <= end)
            goto whileLoopBegin;

    return join(resultVector);
}

#endif
