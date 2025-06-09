#include "Glock.h"

Glock::Glock(const int damagePerRound, const int clipSize, const int remainingAmmo)
    : Pistol(damagePerRound, clipSize, remainingAmmo) {}


bool Glock::fire(PlayerVitalData &enemyPlayerData) {
    constexpr int numberOfBulletsPerTurn = 3;

    for (int i = 0; i < numberOfBulletsPerTurn; ++i) {
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
                healthDamageDealt = this->_damagePerRound * 0.50;
                shieldDamageDealt = this->_damagePerRound * 0.50;
            }

            if (enemyPlayerData.armor > 0 && shieldDamageDealt > enemyPlayerData.armor)
                enemyPlayerData.health -= shieldDamageDealt - enemyPlayerData.armor;

            enemyPlayerData.armor = std::max(0, enemyPlayerData.armor - shieldDamageDealt);
            enemyPlayerData.health = enemyPlayerData.health - healthDamageDealt;
            --this->_currClipBullets;

            std::cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor" << std::endl;

            if (enemyPlayerData.health <= 0)
                return true;
        }
    }
    return enemyPlayerData.health <= 0;
}

// 100 0
// 120 0
// 0 8 9 71
// 1 24 7 35

// 100 50
// 120 50
// 0 12 8 50
// 1 24 4 24

// 200 100
// 120 20
// 1 16 4 3
// 1 24 7 35