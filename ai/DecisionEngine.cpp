#include "ai/DecisionEngine.h"

#include <memory>

#include "ai/EnemyAIController.h"

DecisionEngine::DecisionEngine(ServiceLocator& locator)
    : locator_(locator), enemyController_(std::make_unique<EnemyAIController>(locator)) {}

void DecisionEngine::update(float deltaTime) { enemyController_->update(deltaTime); }
