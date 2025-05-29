#include "ai/DroneBehavior.h"  
#include "entities/Drone.h"  
#include "entities/Player.h"  
#include "core/GameWorld.h"  
#include "core/EventSystem.h"  
#include "ui/CombatLogScreen.h"  
#include "core/ServiceLocator.h" // Ensure ServiceLocator is included  
#include <iostream>  

DroneBehavior::DroneBehavior(ServiceLocator& locator)  
    : Locator_(locator) {}  

void DroneBehavior::Execute(std::shared_ptr<Drone> drone, float deltaTime) {  
    static float attackTimer = 0.0f;  
    static bool firstAttack = true;  
    attackTimer += deltaTime;  
    if (attackTimer >= 3.0f) {  
        auto world = Locator_.Get<GameWorld>();  
        if (!world) {  
            std::cerr << "GameWorld service not found.\n";  
            return;  
        }  

        auto entity = world->GetEntity(1); // assumes player ID=1  
        if (!entity) {  
            std::cerr << "Entity with ID 1 not found.\n";  
            return;  
        }  

        auto player = std::dynamic_pointer_cast<Player>(entity);  
        if (!player) {  
            std::cerr << "Entity is not a Player.\n";  
            return;  
        }  

        std::cout << "Drone " << drone->GetId() << " attacks player!\n";  
        player->ApplyDamage(5);  

        // Log attack to combat screen  
        auto combatLogScreen = Locator_.Get<CombatLogScreen>();  
        if (combatLogScreen) {  
            combatLogScreen->AddEntry(  
                "Drone " + std::to_string(drone->GetId()) + " hits player for 5 damage"  
            );  
        } else {  
            std::cerr << "CombatLogScreen service not found.\n";  
        }  

        if (firstAttack) {  
            auto eventSystem = Locator_.Get<EventSystem>();  
            if (eventSystem) {  
                eventSystem->Emit("EncounteredDrone");  
            } else {  
                std::cerr << "EventSystem service not found.\n";  
            }  
            firstAttack = false;  
        }  

        attackTimer = 0.0f;  
    }  
}
