#include "entities/Trait.h"

Trait::Trait(const std::string& name, const std::string& description, float effectMultiplier)
    : Name_(name), Description_(description), EffectMultiplier_(effectMultiplier) {}

std::string Trait::GetName() const {
    return Name_;
}

std::string Trait::GetDescription() const {
    return Description_;
}

float Trait::GetEffectMultiplier() const {
    return EffectMultiplier_;
}