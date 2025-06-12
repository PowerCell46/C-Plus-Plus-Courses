#include "DeathKnight.h"
#include "Utils.h"


DeathKnight::DeathKnight(const std::string &name, const int maxMana, const int baseManaRegenRate)
    : Hero(name, maxMana, baseManaRegenRate) {}

void DeathKnight::castSpell(const SpellType spell) {
    const std::string HERO_TYPE_NAME = typeid(*this).name();

    if (spell == SpellType::BASIC) {
        if (const int deathCoilNeededManna = this->_spells.at(0).manaCost; deathCoilNeededManna <= this->_currMana) {
            this->_currMana -= deathCoilNeededManna;

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
        if (const int animateDeadNeededManna = this->_spells.at(1).manaCost; animateDeadNeededManna <= this->_currMana) {
            this->_currMana -= animateDeadNeededManna;

            printSuccessfulCastOfSpell(
                this->_name,
                this->_spells.at(1).name,
                this->_spells.at(1).manaCost
            );

            printSuccessfulCastOfSpell(
                this->_name,
                this->_spells.at(0).name,
                0
            );

        } else {
            printUnsuccessfulCastOfSpell(
                this->_name,
                this->_spells.at(1).name
            );
        }
    }
}

void DeathKnight::regenerateMana() {
    this->_currMana = std::min(
        this->_maxMana,
        this->_currMana + this->_manaRegenRate
    );
}