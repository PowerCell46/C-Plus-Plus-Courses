#include "Archmage.h"
#include "Utils.h"

Archmage::Archmage(const std::string &name, const int maxMana, const int baseManaRegenRate, const int manaRegenModifier)
    : Hero(name, maxMana, baseManaRegenRate), _manaRegenModifier(manaRegenModifier){}

void Archmage::castSpell(const SpellType spell) {
    const std::string HERO_TYPE_NAME = typeid(*this).name();

    if (spell == SpellType::BASIC) {
        if (const int waterElementalNeededMana = this->_spells.at(0).manaCost; waterElementalNeededMana <= this->_currMana) {
            this->_currMana -= waterElementalNeededMana;

            printSuccessfulCastOfSpell(
                this->_name,
                this->_spells.at(0).name,
                this->_spells.at(0).manaCost
            );

        } else {
            printUnsuccessfulCastOfSpell(
                this->_name,
                this->_spells.at(0).name
            );
        }

    } else if (spell == SpellType::ULTIMATE) {
        if (const int massTeleportNeededMana = this->_spells.at(1).manaCost; massTeleportNeededMana <= this->_currMana) {
            this->_currMana -= massTeleportNeededMana;

            printSuccessfulCastOfSpell(
                this->_name,
                this->_spells.at(1).name,
                this->_spells.at(1).manaCost
            );

            this->regenerateMana();

        } else {
            printUnsuccessfulCastOfSpell(
                this->_name,
                this->_spells.at(1).name
            );
        }
    }
}

void Archmage::regenerateMana() {
    this->_currMana = std::min(
        this->_maxMana,
        this->_currMana + this->_manaRegenRate * this->_manaRegenModifier
    );
}

