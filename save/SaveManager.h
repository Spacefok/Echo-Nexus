#pragma once
#include "ServiceLocator.h"
#include <string>
#include <unordered_set>
#include <nlohmann/json.hpp>

class ServiceLocator;

// Manages game save and load functionality
class SaveManager {
public:
    explicit SaveManager(const std::string& filePath, ServiceLocator& locator);

    // Load save data from disk
    void load();

    // Save current state to disk
    void save() const;

    // Set current level value
    void setCurrentLevel(int level);
    int getCurrentLevel() const;

private:
    std::string filePath_;
    ServiceLocator& locator_;
    
    // The state being saved
    struct SaveState {
        int currentLevel = 0;
        int playerHealth = 0;
        float playerVirus = 0.0f;
        std::unordered_set<std::string> unlockedFragments;
    } state_;
};
