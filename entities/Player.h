#pragma once

#include "entities/Entity.h"
#include "entities/CloneBody.h"
#include "entities/Trait.h"
#include <memory>
#include <vector>

// Represents the player, holding current body, virus level, and history of bodies
class Player : public Entity {
public:
    // Initialize with unique ID and initial clone body
    Player(std::size_t id, std::shared_ptr<CloneBody> initialBody);

    void setCombatStats(float baseDamage, float weaponMod, float armorClass);


    // Update called each tick (e.g., handle virus effects)
    void update(float deltaTime) override;

    // Health accessors
    int getHealth() const;
    int getMaxHealth() const;

    // Virus getters and modifiers
    float getVirusLevel() const;
    void addVirus(float amount);

    // Apply damage to player
    void applyDamage(int amount);

    // Restore health to player
    void heal(int amount);

    // Handle rebirth into new clone body
    void rebirth(std::shared_ptr<CloneBody> newBody);

    void addTrait(std::shared_ptr<Trait> trait);

    float getArmorClass() const;
    float getBaseDamage() const;
    float getWeaponMod() const;

private:
    // Currently active body
    std::shared_ptr<CloneBody> currentBody_;
    float virusLevel_;
    std::vector<std::shared_ptr<CloneBody>> bodyHistory_;
    std::vector<std::shared_ptr<Trait>> traits_;
    float baseDamage_ = 0.f;
    float weaponMod_ = 0.f;
    float armorClass_ = 0.f;
};
