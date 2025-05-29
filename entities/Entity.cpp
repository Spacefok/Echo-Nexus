#include "entities/Entity.h"

Entity::Entity(std::size_t id)
    : Id_(id)
{}

std::size_t Entity::GetId() const {
    return Id_;
}
