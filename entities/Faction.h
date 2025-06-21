#ifndef ENTITIES_FACTION_H
#define ENTITIES_FACTION_H

#include <string>
#include <unordered_map>

// Represents a faction with relationships to other factions
class Faction {
   public:
    // Construct faction with name
    explicit Faction(const std::string& name);

    // Accessors
    std::string getName() const;

    // Set relationship score (-100 to 100) with another faction
    void setRelationship(const std::string& other, int reputation);
    // Get relationship score, default 0 if not set
    int getRelationship(const std::string& other) const;

   private:
    std::string name_;
    std::unordered_map<std::string, int> relationships_;
};
#endif
