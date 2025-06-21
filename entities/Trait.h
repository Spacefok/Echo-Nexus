#ifndef ENTITIES_TRAIT_H
#define ENTITIES_TRAIT_H

#include <string>

// Represents a character trait that can modify stats or behavior
class Trait {
   public:
    // Construct with name, description, and effect multiplier
    Trait(const std::string& name, const std::string& description, float effectMultiplier);

    // Accessors
    std::string getName() const;
    std::string getDescription() const;
    float getEffectMultiplier() const;

   private:
    std::string name_;
    std::string description_;
    float effectMultiplier_;
};
#endif
