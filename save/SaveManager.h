#pragma once
#include "core/ServiceLocator.h"
#include <string>
#include <unordered_set>
#include <nlohmann/json.hpp>

class ServiceLocator;

// Manages game save and load functionality
class SaveManager {
public:
    explicit SaveManager(const std::string& filePath, ServiceLocator& locator);

    // Load save data from disk
    void Load();

    // Save current state to disk
    void Save() const;

    // Set current level value
    void SetCurrentLevel(int level);
    int GetCurrentLevel() const;

private:
    std::string FilePath_;             // Path to save file
    ServiceLocator& Locator_;          // Access to managers and world
    
    // The state being saved
    struct SaveState {
        int CurrentLevel = 0;
        int PlayerHealth = 0;
        float PlayerVirus = 0.0f;
        std::unordered_set<std::string> UnlockedFragments;
    } State_;
};
