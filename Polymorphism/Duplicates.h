#pragma once

#include <list>
#include <map>
#include <set>
#include "Company.h"

void removeDuplicates(std::list<Company*>& companies) {
    std::map<std::string, Company*> uniqueCompanies;
    std::list<Company*> newCompanies;

    std::set<Company*> deleteCompanies; // Set of unique pointers to be deleted (otherwise causing a double delete: ❌ UNDEFINED BEHAVIOR

    for (Company * company : companies) {
        if (uniqueCompanies.find(company->getName()) == uniqueCompanies.end()) {
            uniqueCompanies.insert({company->getName(), company});
            newCompanies.push_back(company);

        } else if (uniqueCompanies.find(company->getName()) != uniqueCompanies.end() && uniqueCompanies.at(company->getName()) != company) {
            deleteCompanies.insert(company);
        }
    }

    for (Company * deleteCompany : deleteCompanies)
        delete deleteCompany;

    companies = newCompanies;
}
