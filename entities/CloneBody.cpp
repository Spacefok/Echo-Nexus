#include "entities/CloneBody.h"

CloneBody::CloneBody(int maxHealth, float virusRate, float virusCarryover)
    : Health_(maxHealth), MaxHealth_(maxHealth), VirusRate_(virusRate), VirusCarryover_(virusCarryover) {}

int CloneBody::GetHealth() const {
    return Health_;
}

void CloneBody::SetHealth(int health) {
    Health_ = health;
}

int CloneBody::GetMaxHealth() const {
    return MaxHealth_;
}

float CloneBody::GetVirusRate() const {
    return VirusRate_;
}

float CloneBody::GetVirusCarryover() const {
    return VirusCarryover_;
}
