#include "entities/Drone.h"

Drone::Drone(std::size_t id, std::shared_ptr<Faction> faction, const std::string& type,
             int maxHealth, float speed, float damage, float armorClass)
    : Entity(id), health_(maxHealth), maxHealth_(maxHealth), speed_(speed),
      faction_(std::move(faction)), type_(type), damage_(damage), armorClass_(armorClass) {}

void Drone::update(float /*deltaTime*/) {
    // Behavior is driven by AI module via DroneBehavior, so no self-update here
}

int Drone::getHealth() const {
    return health_;
}

int Drone::getMaxHealth() const {
    return maxHealth_;
}

void Drone::setHealth(int health) {
    health_ = (health > maxHealth_ ? maxHealth_ : health);
}

float Drone::getSpeed() const {
    return speed_;
}

std::shared_ptr<Faction> Drone::getFaction() const {
    return faction_;
}

float Drone::getDamage() const { return damage_; }
float Drone::getArmorClass() const { return armorClass_; }
const std::string& Drone::getType() const { return type_; }

