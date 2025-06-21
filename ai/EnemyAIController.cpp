#include "ai/EnemyAIController.h"

#include <memory>

#include "ServiceLocator.h"  // Ensure ServiceLocator is included
#include "ai/DroneBehavior.h"
#include "core/GameWorld.h"
#include "entities/Drone.h"

EnemyAIController::EnemyAIController(ServiceLocator& locator) : locator_(locator) {}

void EnemyAIController::update(float deltaTime) {
    auto world = locator_.get<GameWorld>();
    DroneBehavior behavior(locator_);
    for (auto& entity : world->getEntities()) {
        auto drone = std::dynamic_pointer_cast<Drone>(entity);
        if (drone) {
            behavior.execute(drone, deltaTime);
        }
    }
}
