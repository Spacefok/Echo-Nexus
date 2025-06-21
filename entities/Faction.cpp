#include "entities/Faction.h"

Faction::Faction(const std::string& name) : name_(name) {}

std::string Faction::getName() const { return name_; }

void Faction::setRelationship(const std::string& other, int reputation) {
    relationships_[other] = reputation;
}

int Faction::getRelationship(const std::string& other) const {
    auto it = relationships_.find(other);
    return (it != relationships_.end() ? it->second : 0);
}
