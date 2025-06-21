#include "entities/Trait.h"

Trait::Trait(const std::string& name, const std::string& description, float effectMultiplier)
    : name_(name), description_(description), effectMultiplier_(effectMultiplier) {}

std::string Trait::getName() const {
    return name_;
}

std::string Trait::getDescription() const {
    return description_;
}

float Trait::getEffectMultiplier() const {
    return effectMultiplier_;
}
