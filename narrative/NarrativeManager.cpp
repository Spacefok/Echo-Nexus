#include "narrative/NarrativeManager.h"
#include "narrative/MemoryFragment.h"
#include "narrative/Quest.h"
#include "data/DataManager.h"
#include <nlohmann/json.hpp>

NarrativeManager::NarrativeManager(ServiceLocator& locator)
    : Locator_(locator)
{
    // Подпишемся на событие первого столкновения с дроном
    Locator_.get<EventSystem>()->subscribe(
        "EncounteredDrone",
        [this]() { unlockFragment("first_encounter"); }
    );
}

void NarrativeManager::addQuest(const std::string& id) {
    Quests_[id] = std::make_shared<Quest>(id);
}

void NarrativeManager::completeQuest(const std::string& id) {
    auto it = Quests_.find(id);
    if (it != Quests_.end()) {
        it->second->complete();
    }
}

std::vector<std::shared_ptr<Quest>> NarrativeManager::getQuests() const {
    std::vector<std::shared_ptr<Quest>> quests;
    for (auto& pair : Quests_) {
        quests.push_back(pair.second);
    }
    return quests;
}

void NarrativeManager::startStory(const std::string& startPoint) {
    unlockFragment(startPoint);
}

void NarrativeManager::loadFragments(const std::string& fileName) {
    auto jsonData = Locator_.get<DataManager>()->loadData(fileName);
    for (auto& item : jsonData) {
        std::string id = item.at("id").get<std::string>();
        std::string content = item.at("content").get<std::string>();
        Fragments_[id] = std::make_shared<MemoryFragment>(id, content);
    }
}

void NarrativeManager::update(float /*deltaTime*/) {
    // Placeholder: check game events to unlock fragments
}

void NarrativeManager::unlockFragment(const std::string& id) {
    auto it = Fragments_.find(id);
    if (it != Fragments_.end()) {
        it->second->unlock();
    }
}

std::vector<std::shared_ptr<MemoryFragment>> NarrativeManager::getUnlockedFragments() const {
    std::vector<std::shared_ptr<MemoryFragment>> unlocked;
    for (auto& pair : Fragments_) {
        if (pair.second->isUnlocked()) {
            unlocked.push_back(pair.second);
        }
    }
    return unlocked;
}
