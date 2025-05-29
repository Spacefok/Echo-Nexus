#pragma once

#include <memory>

class ServiceLocator;

// Manages AI behavior for all enemy entities
class EnemyAIController {
public:
    explicit EnemyAIController(ServiceLocator& locator);

    // Update all enemies each tick
    void Update(float deltaTime);

private:
    ServiceLocator& Locator_;
};