#pragma once
#include <vector>
#include <memory>
#include "entities/Entity.h"

// Holds all entities in the game world
class GameWorld {
public:
    void AddEntity(std::shared_ptr<Entity> entity);
    std::shared_ptr<Entity> GetEntity(std::size_t id);
    std::vector<std::shared_ptr<Entity>> GetEntities() const;
    void Update(float deltaTime);

private:
    std::vector<std::shared_ptr<Entity>> Entities_;
};
