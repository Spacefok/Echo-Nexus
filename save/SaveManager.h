#pragma once
#include "core/ServiceLocator.h" // Ensure ServiceLocator is included#include "core/ServiceLocator.h" // Ensure ServiceLocator is included
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

private:
    std::string FilePath_;             // Path to save file
    ServiceLocator& Locator_;          // Access to managers and world
    
    // The state being saved
    struct SaveState {
        int CurrentLevel;
        int PlayerHealth;
        float PlayerVirus;
        std::unordered_set<std::string> UnlockedFragments;
    } State_;
};