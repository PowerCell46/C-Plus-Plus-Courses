#include "DrawRanger.h"
#include "Utils.h"


DrawRanger::DrawRanger(const std::string &name, const int maxMana, const int baseManaRegenRate)
    : Hero(name, maxMana, baseManaRegenRate) {}

void DrawRanger::castSpell(const SpellType spell) {
    const std::string HERO_TYPE_NAME = typeid(*this).name();

    if (spell == SpellType::BASIC) {
        if (const int charmNeededManna = this->_spells.at(0).manaCost; charmNeededManna <= this->_currMana) {
            this->_currMana -= charmNeededManna;

            printSuccessfulCastOfSpell(
                this->_name,
                this->_spells.at(0).name,
                this->_spells.at(0).manaCost
            );

            printSuccessfulCastOfSpell(
                this->_name,
                this->_spells.at(0).name,
                0
            );

        } else {
            printUnsuccessfulCastOfSpell(
                this->_name,
                this->_spells.at(0).name
            );
        }

    } else if (spell == SpellType::ULTIMATE) {
        if (const int silenceNeededManna = this->_spells.at(1).manaCost; silenceNeededManna <= this->_currMana) {
            this->_currMana -= silenceNeededManna;

            printSuccessfulCastOfSpell(
                this->_name,
                this->_spells.at(1).name,
                this->_spells.at(1).manaCost
            );

        } else {
            printUnsuccessfulCastOfSpell(
                this->_name,
                this->_spells.at(1).name
            );
        }
    }
}

void DrawRanger::regenerateMana() {
    this->_currMana = std::min(
        this->_maxMana,
        this->_currMana + this->_manaRegenRate
    );
}
