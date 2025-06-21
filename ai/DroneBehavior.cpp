#include "ai/DroneBehavior.h"

#include <iostream>

#include "ServiceLocator.h"  // Ensure ServiceLocator is included
#include "core/EventSystem.h"
#include "core/GameWorld.h"
#include "entities/Drone.h"
#include "entities/Player.h"
#include "ui/CombatLogScreen.h"

DroneBehavior::DroneBehavior(ServiceLocator& locator) : locator_(locator) {}

void DroneBehavior::execute(std::shared_ptr<Drone> drone, float deltaTime) {
    static float attackTimer = 0.0f;
    static bool firstAttack = true;
    attackTimer += deltaTime;
    if (attackTimer >= 3.0f) {
        auto world = locator_.get<GameWorld>();
        if (!world) {
            std::cerr << "GameWorld service not found.\n";
            return;
        }

        auto entity = world->getEntity(1);  // assumes player ID=1
        if (!entity) {
            std::cerr << "Entity with ID 1 not found.\n";
            return;
        }

        auto player = std::dynamic_pointer_cast<Player>(entity);
        if (!player) {
            std::cerr << "Entity is not a Player.\n";
            return;
        }

        int damage = static_cast<int>(drone->getDamage() * (1 + 0.0f - player->getArmorClass()));
        std::cout << "Drone " << drone->getId() << " attacks player!\n";
        player->applyDamage(damage);

        // Log attack to combat screen
        auto combatLogScreen = locator_.get<CombatLogScreen>();
        if (combatLogScreen) {
            combatLogScreen->addEntry("Drone " + std::to_string(drone->getId()) +
                                      " hits player for " + std::to_string(damage) + " damage");
        } else {
            std::cerr << "CombatLogScreen service not found.\n";
        }

        if (firstAttack) {
            auto eventSystem = locator_.get<EventSystem>();
            if (eventSystem) {
                eventSystem->emit("EncounteredDrone");
            } else {
                std::cerr << "EventSystem service not found.\n";
            }
            firstAttack = false;
        }

        attackTimer = 0.0f;
    }
}
