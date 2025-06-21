#include "entities/Player.h"

#include <algorithm>

Player::Player(std::size_t id, std::shared_ptr<CloneBody> initialBody)
    : Entity(id), currentBody_(initialBody), virusLevel_(0.0f) {
    bodyHistory_.push_back(initialBody);
}

void Player::setCombatStats(float baseDamage, float weaponMod, float armorClass) {
    baseDamage_ = baseDamage;
    weaponMod_ = weaponMod;
    armorClass_ = armorClass;
}

void Player::update(float deltaTime) {
    // Example: virus increases over time
    addVirus(deltaTime * currentBody_->getVirusRate());
    // Clamp virus
    if (virusLevel_ > 100.0f) virusLevel_ = 100.0f;
}

int Player::getHealth() const { return currentBody_->getHealth(); }

int Player::getMaxHealth() const { return currentBody_->getMaxHealth(); }

float Player::getVirusLevel() const { return virusLevel_; }

void Player::addVirus(float amount) { virusLevel_ += amount; }

void Player::applyDamage(int amount) {
    int newHp = getHealth() - amount;
    currentBody_->setHealth(std::max(newHp, 0));
}

void Player::heal(int amount) {
    int newHp = getHealth() + amount;
    if (newHp > getMaxHealth()) newHp = getMaxHealth();
    currentBody_->setHealth(newHp);
}

void Player::rebirth(std::shared_ptr<CloneBody> newBody) {
    currentBody_ = newBody;
    bodyHistory_.push_back(newBody);
    virusLevel_ += currentBody_->getVirusCarryover();
}

void Player::addTrait(std::shared_ptr<Trait> trait) { traits_.push_back(trait); }

float Player::getArmorClass() const { return armorClass_; }
float Player::getBaseDamage() const { return baseDamage_; }
float Player::getWeaponMod() const { return weaponMod_; }
