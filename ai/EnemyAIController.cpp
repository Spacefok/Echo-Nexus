#include "core/ServiceLocator.h" // Ensure ServiceLocator is included  
#include "core/GameWorld.h"  
#include "entities/Drone.h"  
#include "ai/DroneBehavior.h"  
#include <memory>  
#include <EnemyAIController.h>

EnemyAIController::EnemyAIController(ServiceLocator& locator)  
    : Locator_(locator) {}  

void EnemyAIController::Update(float deltaTime) {  
    auto world = Locator_.Get<GameWorld>(); // Fix incomplete type error by including ServiceLocator header  
    DroneBehavior behavior(Locator_);  
    for (auto& entity : world->GetEntities()) {  
        auto drone = std::dynamic_pointer_cast<Drone>(entity);  
        if (drone) {  
            behavior.Execute(drone, deltaTime);  
        }  
    }  
}
