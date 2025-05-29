#pragma once

#include "entities/Entity.h"
#include "entities/Faction.h"
#include <memory>

// Drone entity controlled by AI systems
class Drone : public Entity {
public:
    // Construct with id, faction, health and speed
    Drone(std::size_t id, std::shared_ptr<Faction> faction, int maxHealth, float speed);

    // Update called by GameWorld each tick
    void Update(float deltaTime) override;

    // Health accessors
    int GetHealth() const;
    int GetMaxHealth() const;
    void SetHealth(int health);

    // Movement speed
    float GetSpeed() const;

    // Faction
    std::shared_ptr<Faction> GetFaction() const;

private:
    int Health_;
    int MaxHealth_;
    float Speed_;
    std::shared_ptr<Faction> Faction_;
};