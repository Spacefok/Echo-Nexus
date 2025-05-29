#include "ai/DecisionEngine.h"
#include "ai/EnemyAIController.h"
#include <memory>

DecisionEngine::DecisionEngine(ServiceLocator& locator)
    : Locator_(locator),
      EnemyController_(std::make_unique<EnemyAIController>(locator)) {}

void DecisionEngine::Update(float deltaTime) {
    EnemyController_->Update(deltaTime);
}
