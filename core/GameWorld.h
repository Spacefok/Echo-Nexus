#ifndef CORE_GAMEWORLD_H
#define CORE_GAMEWORLD_H
#include <memory>
#include <vector>

#include "entities/Entity.h"

// Holds all entities in the game world
class GameWorld {
   public:
    void addEntity(std::shared_ptr<Entity> entity);
    std::shared_ptr<Entity> getEntity(std::size_t id);
    std::vector<std::shared_ptr<Entity>> getEntities() const;
    void update(float deltaTime);

   private:
    std::vector<std::shared_ptr<Entity>> entities_;
};
#endif
