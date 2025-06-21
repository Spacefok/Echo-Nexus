#include "entities/Player.h"
#include <algorithm>

Player::Player(std::size_t id, std::shared_ptr<CloneBody> initialBody)
    : Entity(id), CurrentBody_(initialBody), VirusLevel_(0.0f) {
    BodyHistory_.push_back(initialBody);
}

void Player::Update(float deltaTime) {
    // Example: virus increases over time
    AddVirus(deltaTime * CurrentBody_->GetVirusRate());
    // Clamp virus
    if (VirusLevel_ > 100.0f) VirusLevel_ = 100.0f;
}

int Player::GetHealth() const {
    return CurrentBody_->GetHealth();
}

int Player::GetMaxHealth() const {
    return CurrentBody_->GetMaxHealth();
}

float Player::GetVirusLevel() const {
    return VirusLevel_;
}

void Player::AddVirus(float amount) {
    VirusLevel_ += amount;
}

void Player::ApplyDamage(int amount) {
    int newHp = GetHealth() - amount;
    CurrentBody_->SetHealth(std::max(newHp, 0));
}

void Player::Heal(int amount) {
    int newHp = GetHealth() + amount;
    if (newHp > GetMaxHealth()) newHp = GetMaxHealth();
    CurrentBody_->SetHealth(newHp);
}

void Player::Rebirth(std::shared_ptr<CloneBody> newBody) {
    CurrentBody_ = newBody;
    BodyHistory_.push_back(newBody);
    VirusLevel_ += CurrentBody_->GetVirusCarryover();
}
