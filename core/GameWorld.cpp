#include "core/GameWorld.h"

void GameWorld::addEntity(std::shared_ptr<Entity> entity) {
    entities_.push_back(std::move(entity));
}

std::shared_ptr<Entity> GameWorld::getEntity(std::size_t id) {
    for (auto& e : entities_) {
        if (e->getId() == id) return e;
    }
    return nullptr;
}

std::vector<std::shared_ptr<Entity>> GameWorld::getEntities() const {
    return entities_;
}

void GameWorld::update(float deltaTime) {
    for (auto& e : entities_) {
        e->update(deltaTime);
    }
}
