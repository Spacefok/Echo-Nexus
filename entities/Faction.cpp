#include "entities/Faction.h"

Faction::Faction(const std::string& name)
    : Name_(name) {}

std::string Faction::GetName() const {
    return Name_;
}

void Faction::SetRelationship(const std::string& other, int reputation) {
    Relationships_[other] = reputation;
}

int Faction::GetRelationship(const std::string& other) const {
    auto it = Relationships_.find(other);
    return (it != Relationships_.end() ? it->second : 0);
}
