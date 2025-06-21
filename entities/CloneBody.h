#pragma once

// Represents a cloned body template with health and virus characteristics
class CloneBody {
public:
    // Construct with given stats
    CloneBody(int maxHealth, float virusRate, float virusCarryover);

    // Health accessors
    int getHealth() const;
    void setHealth(int health);
    int getMaxHealth() const;

    // Virus properties
    float getVirusRate() const;
    float getVirusCarryover() const;

private:
    int health_;
    int maxHealth_;
    float virusRate_;
    float virusCarryover_;
};
