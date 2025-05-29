#pragma once

#include <string>
#include <unordered_map>

// Represents a faction with relationships to other factions
class Faction {
public:
    // Construct faction with name
    explicit Faction(const std::string& name);

    // Accessors
    std::string GetName() const;

    // Set relationship score (-100 to 100) with another faction
    void SetRelationship(const std::string& other, int reputation);
    // Get relationship score, default 0 if not set
    int GetRelationship(const std::string& other) const;

private:
    std::string Name_;
    std::unordered_map<std::string, int> Relationships_;
};
