#include "entities/CloneBody.h"

CloneBody::CloneBody(int maxHealth, float virusRate, float virusCarryover)
    : health_(maxHealth), maxHealth_(maxHealth), virusRate_(virusRate), virusCarryover_(virusCarryover) {}

int CloneBody::getHealth() const {
    return health_;
}

void CloneBody::setHealth(int health) {
    health_ = health;
}

int CloneBody::getMaxHealth() const {
    return maxHealth_;
}

float CloneBody::getVirusRate() const {
    return virusRate_;
}

float CloneBody::getVirusCarryover() const {
    return virusCarryover_;
}
