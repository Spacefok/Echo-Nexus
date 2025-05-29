#pragma once

// Represents a cloned body template with health and virus characteristics
class CloneBody {
public:
    // Construct with given stats
    CloneBody(int maxHealth, float virusRate, float virusCarryover);

    // Health accessors
    int GetHealth() const;
    void SetHealth(int health);
    int GetMaxHealth() const;

    // Virus properties
    float GetVirusRate() const;
    float GetVirusCarryover() const;

private:
    int Health_;            // Current health
    int MaxHealth_;         // Maximum health
    float VirusRate_;       // Virus growth rate per second
    float VirusCarryover_;  // Virus amount carried when reborn
};