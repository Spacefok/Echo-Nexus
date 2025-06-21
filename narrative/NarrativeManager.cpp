#include "narrative/NarrativeManager.h"
#include "narrative/MemoryFragment.h"
#include "narrative/Quest.h"
#include "data/DataManager.h"
#include <nlohmann/json.hpp>

NarrativeManager::NarrativeManager(ServiceLocator& locator)
    : Locator_(locator)
{
    // Подпишемся на событие первого столкновения с дроном
    Locator_.Get<EventSystem>()->Subscribe(
        "EncounteredDrone",
        [this]() { UnlockFragment("first_encounter"); }
    );
}

void NarrativeManager::AddQuest(const std::string& id) {
    Quests_[id] = std::make_shared<Quest>(id);
}

void NarrativeManager::CompleteQuest(const std::string& id) {
    auto it = Quests_.find(id);
    if (it != Quests_.end()) {
        it->second->Complete();
    }
}

std::vector<std::shared_ptr<Quest>> NarrativeManager::GetQuests() const {
    std::vector<std::shared_ptr<Quest>> quests;
    for (auto& pair : Quests_) {
        quests.push_back(pair.second);
    }
    return quests;
}

void NarrativeManager::StartStory(const std::string& startPoint) {
    UnlockFragment(startPoint);  // разблокировать пролог
}

void NarrativeManager::LoadFragments(const std::string& fileName) {
    auto jsonData = Locator_.Get<DataManager>()->LoadData(fileName);
    for (auto& item : jsonData) {
        std::string id = item.at("id").get<std::string>();
        std::string content = item.at("content").get<std::string>();
        Fragments_[id] = std::make_shared<MemoryFragment>(id, content);
    }
}

void NarrativeManager::Update(float /*deltaTime*/) {
    // Placeholder: check game events to unlock fragments
}

void NarrativeManager::UnlockFragment(const std::string& id) {
    auto it = Fragments_.find(id);
    if (it != Fragments_.end()) {
        it->second->Unlock();
    }
}

std::vector<std::shared_ptr<MemoryFragment>> NarrativeManager::GetUnlockedFragments() const {
    std::vector<std::shared_ptr<MemoryFragment>> unlocked;
    for (auto& pair : Fragments_) {
        if (pair.second->IsUnlocked()) {
            unlocked.push_back(pair.second);
        }
    }
    return unlocked;
}
