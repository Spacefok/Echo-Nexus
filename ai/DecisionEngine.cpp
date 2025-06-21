#include "ai/DecisionEngine.h"
#include "ai/EnemyAIController.h"
#include <memory>

DecisionEngine::DecisionEngine(ServiceLocator& locator)
    : locator_(locator),
      enemyController_(std::make_unique<EnemyAIController>(locator)) {}

void DecisionEngine::update(float deltaTime) {
    enemyController_->update(deltaTime);
}
