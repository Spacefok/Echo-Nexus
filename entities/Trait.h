#pragma once

#include <string>

// Represents a character trait that can modify stats or behavior
class Trait {
public:
    // Construct with name, description, and effect multiplier
    Trait(const std::string& name, const std::string& description, float effectMultiplier);

    // Accessors
    std::string GetName() const;
    std::string GetDescription() const;
    float GetEffectMultiplier() const;

private:
    std::string Name_;
    std::string Description_;
    float EffectMultiplier_;
};