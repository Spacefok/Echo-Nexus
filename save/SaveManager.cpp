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
    : FilePath_(filePath), Locator_(locator) {}

void SaveManager::Load() {
    std::ifstream input(FilePath_);
    if (!input.good()) return;  // no save yet

    nlohmann::json json;
    input >> json;

    State_.CurrentLevel = json.value("currentLevel", 1);
    State_.PlayerHealth = json.value("playerHealth", Locator_.Get<Player>()->GetHealth());
    State_.PlayerVirus = json.value("playerVirus", Locator_.Get<Player>()->GetVirusLevel());
    for (auto& id : json["unlockedFragments"]) {
        State_.UnlockedFragments.insert(id.get<std::string>());
    }

    // Restore narrative fragments
    auto narrative = Locator_.Get<NarrativeManager>();
    for (auto& id : State_.UnlockedFragments) {
        narrative->UnlockFragment(id);
    }
}

void SaveManager::Save() const {
    nlohmann::json json;
    json["currentLevel"] = State_.CurrentLevel;
    auto player = Locator_.Get<Player>();
    json["playerHealth"] = player->GetHealth();
    json["playerVirus"] = player->GetVirusLevel();

    // Save unlocked narrative fragments
    auto fragments = Locator_.Get<NarrativeManager>()->GetUnlockedFragments();
    std::vector<std::string> ids;
    for (const auto& fragPtr : fragments) {
        ids.push_back(fragPtr->GetId());
    }

    std::ofstream output(FilePath_);
    if (!output.is_open()) {
        throw std::runtime_error("Cannot open save file: " + FilePath_);
    }
    output << json.dump(4);
}
