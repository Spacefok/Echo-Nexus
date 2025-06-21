#pragma once
<<<<<<< Updated upstream
#include "core/ServiceLocator.h" // Ensure ServiceLocator is included#include "core/ServiceLocator.h" // Ensure ServiceLocator is included
=======
#include "ServiceLocator.h"
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
=======
    // Set current level value
    void setCurrentLevel(int level);
    int getCurrentLevel() const;

>>>>>>> Stashed changes
private:
    std::string filePath_;
    ServiceLocator& locator_;
    
    // The state being saved
    struct SaveState {
<<<<<<< Updated upstream
        int CurrentLevel;
        int PlayerHealth;
        float PlayerVirus;
        std::unordered_set<std::string> UnlockedFragments;
    } State_;
};
=======
        int currentLevel = 0;
        int playerHealth = 0;
        float playerVirus = 0.0f;
        std::unordered_set<std::string> unlockedFragments;
    } state_;
};
>>>>>>> Stashed changes
