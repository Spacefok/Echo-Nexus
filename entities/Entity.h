#ifndef ENTITIES_ENTITY_H
#define ENTITIES_ENTITY_H

#include <cstddef>

class Entity {
   protected:
    explicit Entity(std::size_t id);

   public:
    virtual ~Entity() = default;

    std::size_t getId() const;

    virtual void update(float deltaTime) = 0;

   private:
    std::size_t id_;
};
#endif
