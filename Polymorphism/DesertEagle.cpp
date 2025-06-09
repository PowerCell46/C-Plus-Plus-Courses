#include "DesertEagle.h"

DesertEagle::DesertEagle(const int damagePerRound, const int clipSize, const int remainingAmmo)
    : Pistol(damagePerRound, clipSize, remainingAmmo) {}


bool DesertEagle::fire(PlayerVitalData &enemyPlayerData) {
    if (this->_currClipBullets == 0) {
        if (this->_remainingAmmo == 0) {
            std::cout << "No ammo left" << std::endl;

            return enemyPlayerData.health <= 0;

        } else {
            const int reloadedBullets = std::min(this->_remainingAmmo, this->_clipSize);
            this->_remainingAmmo -= reloadedBullets;
            this->_currClipBullets += reloadedBullets;

            std::cout << "Reloading..." << std::endl;
            std::cout << "currClipBullets: " << this->_currClipBullets << ", remainingAmmo: " << this->_remainingAmmo << std::endl;
            return enemyPlayerData.health <= 0;
        }

    } else {
        int healthDamageDealt{};
        int shieldDamageDealt{};

        if (enemyPlayerData.armor <= 0) {
            healthDamageDealt = this->_damagePerRound;

        } else {
            healthDamageDealt = this->_damagePerRound * 0.75;
            shieldDamageDealt = this->_damagePerRound * 0.25;
        }

        if (enemyPlayerData.armor > 0 && shieldDamageDealt > enemyPlayerData.armor)
            enemyPlayerData.health -= shieldDamageDealt - enemyPlayerData.armor;

        enemyPlayerData.armor = std::max(0, enemyPlayerData.armor - shieldDamageDealt);
        enemyPlayerData.health = enemyPlayerData.health - healthDamageDealt;
        --this->_currClipBullets;

        std::cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor" << std::endl;
        return enemyPlayerData.health <= 0;
    }
}
