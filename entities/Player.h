#pragma once

#include "entities/Entity.h"
#include "entities/CloneBody.h"
#include <memory>
#include <vector>

// Represents the player, holding current body, virus level, and history of bodies
class Player : public Entity {
public:
    // Initialize with unique ID and initial clone body
    Player(std::size_t id, std::shared_ptr<CloneBody> initialBody);

    // Update called each tick (e.g., handle virus effects)
    void Update(float deltaTime) override;

    // Health accessors
    int GetHealth() const;
    int GetMaxHealth() const;

    // Virus getters and modifiers
    float GetVirusLevel() const;
    void AddVirus(float amount);

    // Apply damage to player
    void ApplyDamage(int amount);

    // Restore health to player
    void Heal(int amount);

    // Handle rebirth into new clone body
    void Rebirth(std::shared_ptr<CloneBody> newBody);

private:
    // Currently active body
    std::shared_ptr<CloneBody> CurrentBody_;
    float VirusLevel_;                     // Accumulated virus corruption
    std::vector<std::shared_ptr<CloneBody>> BodyHistory_;  // All bodies used
};
