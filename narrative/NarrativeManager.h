#pragma once
#include "core/ServiceLocator.h"  
#include "core/EventSystem.h"
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

class ServiceLocator;
class MemoryFragment;

// Manages narrative fragments and quest progression
class NarrativeManager {
public:
    // Construct with access to all services
    explicit NarrativeManager(ServiceLocator& locator);

    // Load fragments from data files
    void loadFragments(const std::string& fileName);

    void startStory(const std::string& startPoint);

    // Update narrative state each tick
    void update(float deltaTime);

    // Unlock a specific fragment by id
    void unlockFragment(const std::string& id);

<<<<<<< Updated upstream
=======
    void addQuest(const std::string& id);
    void completeQuest(const std::string& id);
    std::vector<std::shared_ptr<Quest>> getQuests() const;

>>>>>>> Stashed changes
    // Get unlocked fragments
    std::vector<std::shared_ptr<MemoryFragment>> getUnlockedFragments() const;

private:
<<<<<<< Updated upstream
    ServiceLocator& Locator_;  // Access to DataManager
    std::unordered_map<std::string, std::shared_ptr<MemoryFragment>> Fragments_; // All fragments
};
=======
    ServiceLocator& Locator_;
    std::unordered_map<std::string, std::shared_ptr<MemoryFragment>> Fragments_;
    std::unordered_map<std::string, std::shared_ptr<Quest>> Quests_;
};
>>>>>>> Stashed changes
