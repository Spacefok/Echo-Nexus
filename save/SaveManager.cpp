#include "save/SaveManager.h"
#include "config/ConfigLoader.h"
#include "data/DataManager.h"
#include "core/EventSystem.h"
#include "entities/Player.h"
#include "narrative/MemoryFragment.h"
#include "narrative/NarrativeManager.h" // Add this include to define NarrativeManager
#include "core/GameWorld.h"
#include <fstream>
#include <stdexcept>

SaveManager::SaveManager(const std::string& filePath, ServiceLocator& locator)
    : filePath_(filePath), locator_(locator) {}

void SaveManager::setCurrentLevel(int level) {
    state_.currentLevel = level;
}

int SaveManager::getCurrentLevel() const {
    return state_.currentLevel;
}

void SaveManager::load() {
    std::ifstream input(filePath_);
    if (!input.good()) return;  // no save yet

    nlohmann::json json;
    input >> json;

    state_.currentLevel = json.value("currentLevel", 1);
    auto player = locator_.get<Player>();
    state_.playerHealth = json.value("playerHealth", player->getHealth());
    state_.playerVirus = json.value("playerVirus", player->getVirusLevel());

    int healthDiff = state_.playerHealth - player->getHealth();
    if (healthDiff > 0) {
        player->heal(healthDiff);
    } else if (healthDiff < 0) {
        player->applyDamage(-healthDiff);
    }
    float virusDiff = state_.playerVirus - player->getVirusLevel();
    player->addVirus(virusDiff);

    for (auto& id : json["unlockedFragments"]) {
        state_.unlockedFragments.insert(id.get<std::string>());
    }

    // Restore narrative fragments
    auto narrative = locator_.get<NarrativeManager>();
    for (auto& id : state_.unlockedFragments) {
        narrative->unlockFragment(id);
    }
}

void SaveManager::save() const {
    nlohmann::json json;
    json["currentLevel"] = state_.currentLevel;
    auto player = locator_.get<Player>();
    json["playerHealth"] = player->getHealth();
    json["playerVirus"] = player->getVirusLevel();

    // Save unlocked narrative fragments
    auto fragments = locator_.get<NarrativeManager>()->getUnlockedFragments();
    std::vector<std::string> ids;
    for (const auto& fragPtr : fragments) {
        ids.push_back(fragPtr->getId());
    }
    json["unlockedFragments"] = ids;

    std::ofstream output(filePath_);
    if (!output.is_open()) {
        throw std::runtime_error("Cannot open save file: " + filePath_);
    }
    output << json.dump(4);
}
