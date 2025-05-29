#include "entities/Drone.h"

Drone::Drone(std::size_t id, std::shared_ptr<Faction> faction, int maxHealth, float speed)
    : Entity(id), Health_(maxHealth), MaxHealth_(maxHealth), Speed_(speed), Faction_(faction) {}

void Drone::Update(float /*deltaTime*/) {
    // Behavior is driven by AI module via DroneBehavior, so no self-update here
}

int Drone::GetHealth() const {
    return Health_;
}

int Drone::GetMaxHealth() const {
    return MaxHealth_;
}

void Drone::SetHealth(int health) {
    Health_ = (health > MaxHealth_ ? MaxHealth_ : health);
}

float Drone::GetSpeed() const {
    return Speed_;
}

std::shared_ptr<Faction> Drone::GetFaction() const {
    return Faction_;
}
