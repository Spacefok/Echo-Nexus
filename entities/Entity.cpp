#include "entities/Entity.h"

Entity::Entity(std::size_t id) : id_(id) {}

std::size_t Entity::getId() const { return id_; }
