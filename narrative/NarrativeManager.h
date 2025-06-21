#pragma once
#include "core/ServiceLocator.h"  
#include "core/EventSystem.h"
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

class ServiceLocator;
class MemoryFragment;
class Quest;

// Manages narrative fragments and quest progression
class NarrativeManager {
public:
    // Construct with access to all services
    explicit NarrativeManager(ServiceLocator& locator);

    // Load fragments from data files
    void LoadFragments(const std::string& fileName);

    void StartStory(const std::string& startPoint);

    // Update narrative state each tick
    void Update(float deltaTime);

    // Unlock a specific fragment by id
    void UnlockFragment(const std::string& id);

    void AddQuest(const std::string& id);
    void CompleteQuest(const std::string& id);
    std::vector<std::shared_ptr<Quest>> GetQuests() const;

    // Get unlocked fragments
    std::vector<std::shared_ptr<MemoryFragment>> GetUnlockedFragments() const;

private:
    ServiceLocator& Locator_;  // Access to DataManager
    std::unordered_map<std::string, std::shared_ptr<MemoryFragment>> Fragments_; // All fragments
    std::unordered_map<std::string, std::shared_ptr<Quest>> Quests_;
};