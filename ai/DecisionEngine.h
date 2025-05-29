#pragma once

#include "EnemyAIController.h"  // Ensure complete type for unique_ptr
#include "ServiceLocator.h"
#include <memory>

// Coordinates various AI controllers each tick
class DecisionEngine {
public:
    explicit DecisionEngine(ServiceLocator& locator);

    // Called each tick to update AI
    void Update(float deltaTime);

private:
    ServiceLocator& Locator_;                        // Access to services
    std::unique_ptr<EnemyAIController> EnemyController_;  // Handles enemy AI
};
