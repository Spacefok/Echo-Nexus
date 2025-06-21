#include "core/GameWorld.h"

void GameWorld::AddEntity(std::shared_ptr<Entity> entity) {
    Entities_.push_back(std::move(entity));
}

std::shared_ptr<Entity> GameWorld::GetEntity(std::size_t id) {
    for (auto& e : Entities_) {
        if (e->GetId() == id) return e;
    }
    return nullptr;
}

std::vector<std::shared_ptr<Entity>> GameWorld::GetEntities() const {
    return Entities_;
}

void GameWorld::Update(float deltaTime) {
    for (auto& e : Entities_) {
        e->Update(deltaTime);
    }
}
