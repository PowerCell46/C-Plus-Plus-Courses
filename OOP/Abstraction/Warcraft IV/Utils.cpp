#include "Utils.h"


void printSuccessfulCastOfSpell(const std::string& heroName, const std::string& spellType, const int& manaCost) {
    std::cout << heroName  << " casted " << spellType << " for " << manaCost << " mana\n";
}

void printUnsuccessfulCastOfSpell(const std::string& heroName, const std::string& spellType) {
    std::cout << heroName << " - not enough mana to cast " << spellType << '\n';
}