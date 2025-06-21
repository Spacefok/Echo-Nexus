#ifndef ENTITIES_DRONE_H
#define ENTITIES_DRONE_H

#include <memory>

#include "entities/Entity.h"
#include "entities/Faction.h"

// Drone entity controlled by AI systems
class Drone : public Entity {
   public:
    // Construct with id, faction, health and speed
    Drone(std::size_t id, std::shared_ptr<Faction> faction, const std::string& type, int maxHealth,
          float speed, float damage, float armorClass);

    // Update called by GameWorld each tick
    void update(float deltaTime) override;

    // Health accessors
    int getHealth() const;
    int getMaxHealth() const;
    void setHealth(int health);

    // Movement speed
    float getSpeed() const;

    // Faction
    std::shared_ptr<Faction> getFaction() const;

    float getDamage() const;
    float getArmorClass() const;
    const std::string& getType() const;

   private:
    int health_;
    int maxHealth_;
    float speed_;
    std::shared_ptr<Faction> faction_;
    std::string type_;
    float damage_;
    float armorClass_;
};
#endif
